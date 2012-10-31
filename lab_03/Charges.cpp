#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Charges.h"
using namespace std;

Charges::Charges() {
	_list = NULL;
	_epsilon = 1.;
}

Charges::~Charges() {
	if(_list != NULL) {
	Charge *iter = _list;
	while(iter != NULL) {
	Charge *tnt = iter;
	iter = iter -> next;
	delete tnt;	
	}
}

void Charges::add(int x, int y, int val) {
Charge *newc;
newc = new Charge;
newc -> x = x;
newc -> y = y;
newc -> val = val;
newc -> next = NULL;
if(_list == NULL) {
_list = newc;	
} else {
Charge *iter;
for(iter = _list; iter -> next != NULL; iter = iter -> next);
iter -> next = newc;
}
}

int Charges::n() {
int i = 0;
for(iter = _list; iter != NULL; iter = iter -> next) {
i++;	
}
return i;
}

float Charges::force(int nx, int ny, int nval) {
	float f_x = 0;
	float f_y = 0;
	for(Charge *iter = _list; iter != NULL; iter = iter -> next) {
		float r = hypot(nx - (iter -> x), ny - (iter -> y));
		f_x += nval*(iter -> val)*(nx - (iter -> x))/(_epsilon_zero*_epsilon*4*PI*r*r*r);
		f_y += nval*(iter -> val)*(ny - (iter -> y))/(_epsilon_zero*_epsilon*4*PI*r*r*r);
	}
	return sqrt((f_x*f_x)+(f_y*f_y));
}

float& Charges::epsilon() {
return _epsilon;	
}
