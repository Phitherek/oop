#include <iostream>
#include <cstdlib>
#include <string>
#include "Arg.h"
using namespace std;

Arg::Arg(string s) {
_val = s;	
}

Arg::Arg() {
_val = "";	
}

Arg::operator int() {
int v;
v = atoi(_val.c_str());
return v;
}

Arg::operator string() {
	return _val;
}

Arg::operator float() {
float v;
v = atof(_val.c_str());
return v;
}
