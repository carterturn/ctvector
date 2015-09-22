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

#include "ctvector.h"
#include <cmath>

#ifdef openblas
#include <openblas/cblas.h>
#endif

// This function rotates a vector. It probably works.
ctvector ctvector::rotate(float tx, float ty, float tz){
	
	ctvector xrot(0.0f, 0.0f, 0.0f);
	//First, x rotation
	xrot.x = x;
	xrot.y = y*cos(tx) - z*sin(tx);
	xrot.z = y*sin(tx) + z*cos(tx);
	
	ctvector yrot(0.0f, 0.0f, 0.0f);
	//Then, y rotation
	yrot.x = xrot.x*cos(ty) + xrot.z*sin(ty);
	yrot.y = xrot.y;
	yrot.z = -1*xrot.x*sin(ty) + xrot.z*cos(ty);
	
	ctvector zrot(0.0f, 0.0f, 0.0f);
	//Finally, z rotation
	zrot.x = yrot.x*cos(tz) - yrot.y*sin(tz);
	zrot.y = yrot.x*sin(tz) + yrot.y*cos(tz);
	zrot.z = yrot.z;
	
	x = zrot.x;
	y = zrot.y;
	z = zrot.z;
	
	return zrot;
}

ctvector ctvector::operator+(const ctvector& param){
	ctvector result;
	
	result.x = x + param.x;
	result.y = y + param.y;
	result.z = z + param.z;
	
	return result;
}

ctvector ctvector::operator-(const ctvector& param){
	ctvector result;
	
	result.x = x - param.x;
	result.y = y - param.y;
	result.z = z - param.z;
	
	return result;
}

ctvector ctvector::operator*(const float& scalar){
	ctvector result;
	
	result.x = x*scalar;
	result.y = y*scalar;
	result.z = z*scalar;
	
	return result;
}

// Dot product
float ctvector::operator*=(const ctvector& param){

#ifdef openblas
	float array[3];
	float paramarray[3];

	array[0] = x;
	array[1] = y;
	array[2] = z;

	paramarray[0] = param.x;
	paramarray[1] = param.y;
	paramarray[2] = param.z;

	return cblas_sdot(3, array, 1, paramarray, 1);
#else
	ctvector result;

	result.x = x * param.x;
	result.y = y * param.y;
	result.z = z * param.z;

	return result.x + result.y + result.z;
#endif
}

// Cross (+) product
ctvector ctvector::operator+=(const ctvector& param){
	ctvector result;

	result.x = y*param.z - z*param.y;
	result.y = z*param.x - x*param.z;
	result.z = x*param.y - y*param.x;

	return result;
}
