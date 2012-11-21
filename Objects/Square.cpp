#include <iostream>
#include <cstdlib>
#include "Square.h"
using namespace std;

Square::Square() {
_x = 0;
_y = 0;
}

Square::Square(int x) {
if(x >= 0) {
_x = x;
_y = x;
} else {
_x = 0;
_y = 0;
cerr << "Bad size of a square!" << endl;
}	
}

Square::~Square() {
_x = 0;
_y = 0;
}

Square& Square::setSize(int x) {
if(x >= 0) {
_x = x;
_y = x;
} else {
_x = 0;
_y = 0;
cerr << "Bad size of a square!" << endl;
}
return *this;
}

int Square::getSize() {
return _x;	
}
