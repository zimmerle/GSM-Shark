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

#ifndef GNURADIOWORKER_H
#define GNURADIOWORKER_H

#include <QtCore/QObject>
#include <QtCore/QThread>
#include <QtCore/QDebug>
#include <gr_uhd_api.h>
#include <gr_sync_block.h>

#include "common.h"

#include <gr_head.h>
#include <gr_io_signature.h>
#include <gr_null_source.h>
#include <gr_sync_block.h>
#include <gr_top_block.h>
#include <gr_uhd_usrp_source.h>
#include <gr_uhd_api.h>
#include <gr_vector_sink_b.h>

class GnuradioWorker : public QThread
{
    Q_OBJECT

public:
    explicit GnuradioWorker(QObject *parent = 0);
    ~GnuradioWorker();

    GsmShark::RadioStatus m_radioConnected;
    static double sampleRate;
    static double gain;
    static double numberOfSamples;
    void stop(void);

protected:
    void run();
    QList<double> m_queue;

private:
    void setupTheRadio();
    boost::shared_ptr<uhd_usrp_source> m_usrp;
    gr_top_block_sptr m_tb;

signals:
    void clear();
    void missing(int amout);
    void radioStatus(int);

public slots:
    void newFreq(double freq);

};


#endif // GNURADIOWORKER_H
