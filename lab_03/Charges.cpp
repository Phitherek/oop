#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Charges.h"
using namespace std;

double Charges::_epsilon;

Charges::Charges() {
	_list = NULL;
	_epsilon = 1.;
}

Charges::Charges(const Charges& c) {
_list = NULL;
_epsilon = c._epsilon;
Charge *iter;
for(iter = c._list; iter != NULL; iter = iter -> next) {
Charge *newc;
newc = new Charge;
newc -> x = iter -> x;
newc -> y = iter -> y;
newc -> val = iter -> val;
newc -> next = NULL;
if(_list == NULL) {
_list = newc;
} else {
Charge *iter2;
for(iter2 = _list; iter2 -> next != NULL; iter2 = iter2 -> next);
iter2 -> next = newc;
}
}
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
_list = NULL;
}

Charges& Charges::add(int x, int y, int val) {
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
return *this;
}

int Charges::n() {
int i = 0;
for(Charge* iter = _list; iter != NULL; iter = iter -> next) {
i++;	
}
return i;
}

Force Charges::force(int nx, int ny, int nval) {
	float f_x = 0;
	float f_y = 0;
	Force f;
	for(Charge *iter = _list; iter != NULL; iter = iter -> next) {
		float r = hypot(nx - (iter -> x), ny - (iter -> y));
		f_x += nval*(iter -> val)*(nx - (iter -> x))/(_epsilon_zero*_epsilon*4*PI*r*r*r);
		f_y += nval*(iter -> val)*(ny - (iter -> y))/(_epsilon_zero*_epsilon*4*PI*r*r*r);
	}
	f.x = f_x;
	f.y = f_y;
	return f;
}

double& Charges::epsilon() {
return _epsilon;	
}
