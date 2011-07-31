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

#ifndef ARFCN_H
#define ARFCN_H

class Arfcn
{
public:
    Arfcn();

    static double toFrequency(int arfcn);
    static int toArfcn(double freq);
};

#endif // ARFCN_H
