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

#define GMP
#define GRAPHICS

#include <sstream>
#ifdef GMP
#include <gmpxx.h>
#endif

class ctvector{
public:
#ifdef GMP
	ctvector(mpf_class ctvx, mpf_class ctvy, mpf_class ctvz){
#else
	ctvector(float ctvx, float ctvy, float ctvz){
#endif
		x = ctvx;
		y = ctvy;
		z = ctvz;
	}
	
	ctvector(){
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	std::string to_string();

	// Proximity definition results in functioning as an array
	// i.e. &x[0] == x, &x[1] == y, &x[2] == z
#ifdef GMP
        mpf_class x;
        mpf_class y;
        mpf_class z;
#else
	float x;
	float y;
	float z;
#endif	
	
	ctvector rotate(double tx, double ty, double tz);
	
	ctvector operator+ (const ctvector& param);
	ctvector operator- (const ctvector& param);
#ifdef GMP
	mpf_class operator*= (const ctvector& param);	
#else
	double operator*= (const ctvector& param);
#endif
	
        ctvector operator* (const int& scalar);
        ctvector operator* (const double& scalar);
        ctvector operator* (const float& scalar);
#ifdef GMP
        ctvector operator* (const mpf_class& scalar);
#endif
	
	// Products (dot and cross)
	ctvector operator+= (const ctvector& param);

#ifdef GMP
	mpf_class abs();
#else
	double abs();
#endif
	
#ifdef GRAPHICS
        void draw(ctvector in);
        void draw();
#endif
};

#ifdef GMP
mpf_class abs(ctvector input);
#else
double abs(ctvector input);
#endif

#ifdef GRAPHICS
void gldraw(ctvector in);
#endif
