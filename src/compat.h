// This file is part of the brlaser printer driver.
//
// Copyright 2021 Evan Miller
//
// brlaser is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// brlaser is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with brlaser.  If not, see <http://www.gnu.org/licenses/>.

#ifndef COMPAT_H
#define COMPAT_H

#include <cups/cups.h>

#if CUPS_VERSION_MAJOR == 1 && CUPS_VERSION_MINOR < 2
#define _BRLASER_CUPS_COMPAT_OLD
#define cups_page_header2_t cups_page_header_t
#define cupsRasterReadHeader2(r, h) cupsRasterReadHeader(r, h)
#endif

#endif
