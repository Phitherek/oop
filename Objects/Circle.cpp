#include <iostream>
#include <cstdlib>
#include "Circle.h"
using namespace std;

Circle::Circle() {
_r = 0;	
}

Circle::Circle(int r) {
if(r >= 0) {
_r = r;
} else {
_r = 0;
cerr << "Bad radius of a circle!" << endl;
}
}

Circle::~Circle() {
_r = 0;	
}

Circle& Circle::setR(int r) {
	if(r >= 0) {
_r = r;
} else {
_r = 0;
cerr << "Bad radius of a circle!" << endl;
}
return *this;
}

int Circle::getR() {
return _r;	
}

void Circle::draw() {
cout << "Circle::draw():" << endl << "desc: " << _desc << endl << "r: " << _r << endl;	
}
