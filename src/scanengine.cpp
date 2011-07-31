/*
 *
 * Copyright (C) 2011 Felipe Zimmerle <felipe at zimmerle dot org>.
 * All rights reserved.
 *
 * This file is part of Gsmdog.
 *
 * Gsmdog is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Gsmdog is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Gsmdog. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */

#include "scanengine.h"
#include <QDebug>

ScanEngine::ScanEngine(QObject *parent) :
    QObject(parent),
    m_stillMissing(0),
    m_total(0)
{
    m_worker = new GnuradioWorker();
    m_worker->start();

    QObject::connect(this, SIGNAL(newFreq(double)), m_worker, SLOT(newFreq(double)));
    QObject::connect(m_worker, SIGNAL(clear()), this, SLOT(finished()));
    QObject::connect(m_worker, SIGNAL(missing(int)), this, SLOT(missing(int)));
    QObject::connect(m_worker, SIGNAL(radioStatus(int)), this, SIGNAL(radioStatus(int)));
}

void ScanEngine::finished()
{
    emit scanFinished();
}

void ScanEngine::stopScan()
{
    //m_worker->stop();
    emit scanFinished();
}

void ScanEngine::missing(int amount)
{
    m_stillMissing = amount;
}

void ScanEngine::startScan(QString channels)
{
    QList<int> arfcns = parserChannels(channels);
    m_total = arfcns.count();

    for (int i = 0; i < arfcns.count(); i++)
    {
        emit newFreq(Arfcn::toFrequency(arfcns.at(i)));
    }

}

QList<int> ScanEngine::parserChannels(QString freqs)
{
    QList<int> frequencies;
    QStringList blocks = freqs.split(";");

    for (int i = 0; i < blocks.count(); i++)
    {
        QString range = blocks.at(i);

        if (range.size() == 0)
        {
            continue;
        }

        QStringList rangeSplit =  blocks.at(i).split("-");
        if (rangeSplit.count() == 1)
        {
            frequencies.append(rangeSplit.at(0).toInt());
            continue;
        }
        else
        {
            int start = rangeSplit.at(0).toInt();
            int end = rangeSplit.at(1).toInt();

            if (end < start)
            {
                end, start = start, end;
                qDebug() << this << "::" << "Are you idiot?" << end << "is bigger then" << start << " (Swapping the values...)";
            }

            while (end >= start)
            {
                frequencies.append(start++);
            }

        }
    }

    return frequencies;
}
