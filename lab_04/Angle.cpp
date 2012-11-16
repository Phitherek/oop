#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Angle.h"
using namespace std;

Angle::Angle() {
	_val = 0;	
}

Angle Angle::fromRadians(float rad) {
	Angle a;
	a._val = fmod ( rad , 2* M_PI);
	return a;
}

Angle Angle::fromDegrees(int deg) {
	float rad = static_cast<float>(deg)/360*2*M_PI;

	Angle a = Angle::fromRadians ( rad); 
	return a;
}


ostream& operator<<(ostream &o, const Angle &a) {
o << a._val;
}

Angle::operator double() const {
	return static_cast<double>(_val);
}

Angle Angle::add(Angle a) {
_val += a._val;
return *this;
}

Angle Angle::distance(Angle a1, Angle a2) {
Angle res = Angle::fromRadians(0.);
if(a1._val > a2._val) {
res._val = a1._val - a2._val;	
} else {
res._val = a2._val - a1._val;	
}
return res;
}

float Angle::toDeg() {
float deg;
float rad;
rad = _val;
rad = rad/(2*M_PI);
deg = rad*360;
while(deg > 360) {
deg = deg - 360;
}
deg = 360 - deg;
return deg;
}
