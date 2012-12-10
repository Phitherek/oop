#include <iostream>
#include <cstdlib>
#include "LongOpt.h"
using namespace std;

LongOpt::LongOpt(string s) {
	_key = s;	
}

LongOpt::~LongOpt() {
	_key = "";	
}

int LongOpt::check(const char** argv, int argc) {
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			if(argv[i][1] == '-') {
				string s = "";
				for(int j = 2; argv[i][j] != '\000'; j++) {
				s += argv[i][j];	
				}
				if(s == _key) {
					_pres = 1;
					_pos = i;
					return _pos;
				}
			}
		}
	}
return _pos;
}

string LongOpt::key() {
	return _key;
}
