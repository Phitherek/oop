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

int Opt::check(const char** argv, int argc) {
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

opt::invalid_argument::invalid_argument() {
_option = "";
_badarg = "";
}

opt::invalid_argument::~invalid_argument() throw() {
_option = "";
_badarg = "";
}

opt::invalid_argument::invalid_argument(std::string option, std::string badarg) {
_option = option;
_badarg = badarg;
}

const char* opt::invalid_argument::what() const throw() {
string s = "";
s += _option;
s += " ";
s += _badarg;
return s.c_str();
}

opt::unknown_option::unknown_option() {
_what = "";	
}

opt::unknown_option::~unknown_option() throw() {
_what = "";	
}

opt::unknown_option::unknown_option(std::string s) {
_what = s;	
}

const char* opt::unknown_option::what() const throw() {
return _what.c_str();	
}
