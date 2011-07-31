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

#include "arfcn.h"
#include <QDebug>


Arfcn::Arfcn()
{
}


double Arfcn::toFrequency (int arfcn)
{
    if (arfcn > 0 && arfcn <= 124)
    {
        return 890 + 0.2 * arfcn + 45;
    }

    if (arfcn >= 512 && arfcn <= 885)
    {
        return 1710.2 + 0.2 * (arfcn - 512) + 95;
    }

    return -1;
}

int Arfcn::toArfcn (double freq)
{
    int a = 0;
    return a;
}
