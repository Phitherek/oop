#include <iostream>
#include <cstdlib>
#include "ShortOpt.h"
using namespace std;

ShortOpt::ShortOpt(char c) {
	_key = c;	
}

int ShortOpt::check(const char** argv, int argc) {
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			if (argv[i][1] != '-') {
				if(argv[i][1] == _key) {
					_pres = 1;
					_pos = i;
					return _pos;
				}
			}
	}
}
return _pos;
}

string ShortOpt::key() {
	string k;
	k += _key;
	return k;
}
