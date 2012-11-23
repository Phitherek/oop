#include <iostream>
#include <cstdlib>
#include "ShortOptWithArg.h"
using namespace std;

ShortOptWithArg::ShortOptWithArg(char c, Arg arg): ShortOpt(c) {
	_arg = arg;	
}

Arg ShortOptWithArg::arg() {
	return _arg;	
}

int ShortOptWithArg::check(char** argv, int argc) {
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
			_arg = Arg(a);
			return _pos;
		}
	}
	return _pos;	
}
