#include <iostream>
#include <cstdlib>
#include <string>
#include "Opt.h"
using namespace std;

Opt::Opt() {
	_pos = -1;
	_pres = 0;
}

Opt::~Opt() {
	_pos = -1;
	_pres = 0;
}

int Opt::check(char** argv, int argc) {
	cerr << "Ouch, not this one..." << endl;
	exit(1);
}

std::string Opt::key() {
	cerr << "Ouch, not this one..." << endl;
	exit(1);
}

int Opt::present() {
	return _pres;	
}
