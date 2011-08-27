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

#ifndef SCANENGINE_H
#define SCANENGINE_H

#include <QObject>
#include <QDebug>
#include <QStringList>

#include "radio.h"
#include "gnuradioworker.h"
#include "arfcn.h"

class ScanEngine : public QObject
{
    Q_OBJECT

public:
    explicit ScanEngine(QObject *parent = 0);

protected:
    QList<int> parserChannels(QString freqs);
    int m_stillMissing;
    int m_total;
    GnuradioWorker *m_worker;

signals:
    void newFreq(double);
    void scanFinished();
    void radioStatus(int status);
    void progress(int processed, int total);

protected slots:
    void missing(int missing);

public slots:
    void startScan(QString);
    void stopScan();
    void finished();
};

#endif // SCANENGINE_H
