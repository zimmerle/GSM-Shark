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

#ifndef COMMON_H
#define COMMON_H

#define GSMDOG_VERSION "0.1 alpha"


namespace Gsmdog
{
    enum viewType { Maps, List };
    enum RadioStatus {Connected, Disconnected};

};

Q_DECLARE_METATYPE(Gsmdog::viewType);
Q_DECLARE_METATYPE(Gsmdog::RadioStatus);

#endif // COMMON_H
