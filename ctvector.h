/*
  Copyright 2015 Carter Turnbaugh

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

class ctvector{
public:
	ctvector(float ctvx, float ctvy, float ctvz){
		x = ctvx;
		y = ctvy;
		z = ctvz;
	}
	ctvector(){
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	
	float x;
	float y;
	float z;
	
	ctvector rotate(float tx, float ty, float tz);
	
	ctvector operator+ (const ctvector& param);
	ctvector operator- (const ctvector& param);
	ctvector operator* (const float& scalar);

	// Products (dot and cross)
	ctvector operator*= (const ctvector& param);
	ctvector operator+= (const ctvector& param);
};
