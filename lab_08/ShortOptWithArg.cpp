#include <iostream>
#include <cstdlib>
#include "ShortOptWithArg.h"
using namespace std;

ShortOptWithArg::ShortOptWithArg(char c, Arg arg): ShortOpt(c) {
	_arg = arg;
	_checker = NULL;	
}

ShortOptWithArg::ShortOptWithArg(char c, Arg arg, Validation* checker): ShortOpt(c) {
	bool res = checker -> check(arg);
	if(res == true) {
	_arg = arg;
	_checker = checker;	
	} else {
	throw opt::invalid_argument(key(), arg);	
	}
}

ShortOptWithArg::~ShortOptWithArg() {
	if(_checker != NULL) {
	delete _checker;	
	}
	_arg = Arg("");	
}

Arg ShortOptWithArg::arg() {
	return _arg;	
}

int ShortOptWithArg::check(const char** argv, int argc) {
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			if (argv[i][1] != '-') {
				if(argv[i][1] == _key) {
					_pres = 1;
					_pos = i;
				}
			}
		} else if(_pres == 1) {
			string a;
			a = argv[i];
			if(_checker -> check(a) == true) {
			_arg = Arg(a);
			} else {
			throw opt::invalid_argument(key(), a);
			}
			return _pos;
		}
	}
	return _pos;	
}
