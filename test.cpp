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

#include <iostream>
#include <chrono>
#include <ctvector/ctvector.h>
#include <gmpxx.h>

using namespace std;

void printvector(ctvector v){
	cout << v.to_string() << "\n";
}

int main(int argc, char * argv[]){

	ctvector a(1.0_mpf, 1.0_mpf, 0.0_mpf);
	ctvector b(1.0_mpf, 0.0_mpf, 2.0_mpf);

	cout << "Created\n";

	chrono::high_resolution_clock::time_point before;
	chrono::high_resolution_clock::time_point after;
	ctvector res;
	
	// Addition
	before = chrono::high_resolution_clock::now();
	for(int i = 0; i < 1000000; i++){
		res = a+b;
	}
	after = chrono::high_resolution_clock::now();

	cout << "Addition\n";
	printvector(res);
	cout << chrono::duration_cast<chrono::duration<double>>(after - before).count() << "\n";

	// Subtraction
	before = chrono::high_resolution_clock::now();
	for(int i = 0; i < 1000000; i++){
		res = a-b;
	}
	after = chrono::high_resolution_clock::now();

	cout << "Subtraction\n";
	printvector(res);
	cout << chrono::duration_cast<chrono::duration<double>>(after - before).count() << "\n";

	// Scalar multiplication
	before = chrono::high_resolution_clock::now();
	for(int i = 0; i < 1000000; i++){
		res = a*3.0f;
	}
	after = chrono::high_resolution_clock::now();

	cout << "Scalar multiplication\n";
	printvector(res);
	cout << chrono::duration_cast<chrono::duration<double>>(after - before).count() << "\n";

	mpf_class result;
	// Dot product
	before = chrono::high_resolution_clock::now();
	for(int i = 0; i < 1000000; i++){
		result = a*=b;
	}
	after = chrono::high_resolution_clock::now();

	cout << "Dot product\n";
	cout << result.get_d() << "\n";
	cout << chrono::duration_cast<chrono::duration<double>>(after - before).count() << "\n";

	// Cross product
	before = chrono::high_resolution_clock::now();
	for(int i = 0; i < 1000000; i++){
		res = a+b;
	}
	after = chrono::high_resolution_clock::now();

	cout << "Cross product\n";
	printvector(res);
	cout << chrono::duration_cast<chrono::duration<double>>(after - before).count() << "\n";

	// Rotation
	res = ctvector(1.0f, 0.0f, 1.0f);
	before = chrono::high_resolution_clock::now();
	for(int i = 0; i < 1000000; i++){
		res.rotate(0.1f, 0.0f, 0.2f);
	}
	after = chrono::high_resolution_clock::now();

	cout << "Rotation\n";
	printvector(res);
	cout << chrono::duration_cast<chrono::duration<double>>(after - before).count() << "\n";

	return 0;
}
