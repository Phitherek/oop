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
float newrad = rad;
if(rad < 0) {
 newrad = -newrad;
 if(newrad > 2*M_PI) {
   int n = 2;
   while(newrad - n*M_PI > 2*M_PI) {
   n += 2;  
   }
   newrad -= n*M_PI;
   newrad = 2*M_PI - newrad;	
 }  	
}
  	
if(rad > 2*M_PI) {  	
  int n = 2;
    while(newrad - n*M_PI > 2*M_PI) {
    n += 2;  
    }
    newrad -= n*M_PI;
}
  	
a._val = newrad;
}

Angle Angle::fromDegrees(int deg) {
	float rad = static_cast<float>(deg)/360*2*M_PI;

	Angle a = Angle::fromRadians ( rad); 
	return a;
}


ostream& operator<<(ostream &o, const Angle &a) {
o << a._val << endl;
return o;
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
return deg;
}
