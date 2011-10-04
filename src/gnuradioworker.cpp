/*
 *
 * Copyright (C) 2011 Felipe Zimmerle <felipe at zimmerle dot org>.
 * All rights reserved.
 *
 * This file is part of GsmShark.
 *
 * GsmShark is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GsmShark is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GsmShark. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */

#include "gnuradioworker.h"

#include <QtCore/QDateTime>
#include <QtCore/QDebug>


double GnuradioWorker::sampleRate = 571428;
double GnuradioWorker::gain = 50;
double GnuradioWorker::numberOfSamples = 2285712;

GnuradioWorker::GnuradioWorker(QObject *parent) :
    QThread(parent),
    m_radioConnected(GsmShark::Disconnected)
{
}

GnuradioWorker::~GnuradioWorker()
{
    wait();
}

void GnuradioWorker::setupTheRadio()
{
    m_tb = gr_make_top_block("top");
    const uhd::device_addr_t device_addr = uhd::device_addr_t("type=usrp1");

    try {
        m_usrp = uhd_make_usrp_source(device_addr, uhd::io_type_t::COMPLEX_FLOAT32, 1);

        uhd::io_type_t duh = uhd::io_type_t::COMPLEX_FLOAT32;

        gr_vector_sink_b_sptr vector = gr_make_vector_sink_b(duh.size);


        gr_head_sptr head = gr_make_head(sizeof(gr_complex), numberOfSamples);

        (m_usrp)->set_samp_rate(sampleRate);
        (m_usrp)->set_gain(gain, 0);

        m_tb->connect(m_usrp, 0, head, 0);
        m_tb->connect(head, 0, vector, 0);
        m_radioConnected = GsmShark::Connected;

        emit radioStatus(m_radioConnected);
    }
    catch (uhd::key_error e)
    {
        m_radioConnected = GsmShark::Disconnected;
        qDebug() << this << "::" << "Radio not found. trying again later. (Sleeping for 5 seconds.)";
        emit radioStatus(m_radioConnected);
        QThread::sleep(5);
    }
}

void GnuradioWorker::newFreq(double freq)
{
    m_queue.append(freq);
}

void GnuradioWorker::stop(void)
{
    m_queue.clear();
}

void GnuradioWorker::run()
{
    forever
    {
        if (m_radioConnected != GsmShark::Connected)
        {
            setupTheRadio();
        }

        if (m_radioConnected == GsmShark::Connected && !m_queue.isEmpty())
        {
            double freq = m_queue.takeFirst();

            emit missing(m_queue.count()+1);

            uhd::tune_request_t treq = uhd::tune_request_t(freq);
            uhd::tune_result_t tune_r = (m_usrp)->set_center_freq(treq);

            qDebug() << this << "::" << QDateTime::currentDateTime() << "Starting... (" << freq << ")";
            m_tb->run();
            qDebug() << this << "::" << QDateTime::currentDateTime() << "Done!";

            if (m_queue.isEmpty())
            {
                emit clear();
            }
            else
            {
                continue;
            }
        }

        QThread::sleep(1);
    }
}

