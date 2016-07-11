/*
  Copyright 2016 Carter Turnbaugh

  This file is part of Terca C++ Vector.

  Terca C++ Vector is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Terca C++ Vector is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Terca C++ Vector.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "ctvector.h"

class ctline{
public:
	ctline(ctvector p1, ctvector p2){
		point1 = p1;
		point2 = p2;
	}
	
	ctvector point1;
	ctvector point2;

	ctline rotate(double tx, double ty, double tz);

};
