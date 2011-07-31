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

#include <QtGui/QApplication>
#include "mainwin.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow *main = new MainWindow();
    main->show();

    ScanEngine *scanEngine = new ScanEngine();
    QObject::connect(scanEngine, SIGNAL(scanFinished()), main, SLOT(scanFinished()));
    QObject::connect(main, SIGNAL(startScan(QString)), scanEngine, SLOT(startScan(QString)));
    QObject::connect(main, SIGNAL(stopScan()), scanEngine, SLOT(stopScan()));

    return app.exec();
}
