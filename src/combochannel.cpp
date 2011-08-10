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
#include "combochannel.h"

ComboChannel::ComboChannel(QWidget *parent) :
    QComboBox(parent)
{
    setupUi();

    QObject::connect(this, SIGNAL(activated(int)), this, SLOT(newBandSelected(int)));
}

void ComboChannel::setupUi()
{
    addItem("GSM 450","259-239;");
    addItem("GSM 450","306-340;");
    addItem("GSM 480","438-511;");
    addItem("GSM 750","128-251;");
    addItem("GSM 850","128-251;");
    addItem("P-GSM-900","1-124;");
    addItem("E-GSM-900","975-1023;0-124;");
    addItem("R-GSM-900","955-1023;0-124;");
    addItem("DCS-1800","512-885;");
    addItem("PCS-1900","512-810;");
}

void ComboChannel::newBandSelected(int item)
{
    QVariant variant = itemData(item);
    emit newRange(variant.value<QString>());
}
