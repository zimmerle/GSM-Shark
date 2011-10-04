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

#ifndef COMBOCHANNEL_H
#define COMBOCHANNEL_H

#include <QtGui/QComboBox>

class ComboChannel : public QComboBox
{
    Q_OBJECT
public:
    explicit ComboChannel(QWidget *parent = 0);

signals:
    void newRange(QString);

public slots:
    void newBandSelected(int item = 1);

private:
    void setupUi();
};

#endif // COMBOCHANNEL_H
