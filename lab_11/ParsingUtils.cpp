#include <iostream>
#include <cstdlib>
#include "ParsingUtils.h"

Exact::Exact(std::string match) {
	_match = match;	
}

Exact::~Exact() {
	_match = "";	
}

Contains::Contains(std::string match) {
	_match = match;	
}

Contains::~Contains() {
	_match = "";	
}

StartsWith::StartsWith(std::string match) {
	_match = match;	
}

StartsWith::~StartsWith() {
	_match = "";	
}

std::istream& operator>>(std::istream& in, Exact match) {
	std::string s;
	in >> s;
	if(s.length() != match._match.length()) {
		in.setstate(std::ios::badbit);
	} else {
		for(unsigned int i = 0; i < s.length(); i++) {
			if(s[i] != match._match[i]) {
				in.setstate(std::ios::badbit);
				break;
			}
		}
	}
	return in;
}

std::istream& operator>>(std::istream& in, Contains match) {
	std::string s;
	in >> s;
	bool pmatches = false;
	for(unsigned int i = 0; i < s.length(); i++) {
		if(s[i] == match._match[0]) {
			bool matches = true;
		for(unsigned int j = i; j < match._match.length(); j++) {
			if(s[j] != match._match[j-i]) {
			matches = false;
			break;	
			}
		}
		if(matches == true) {
			pmatches = true;
			break;
		}
	}
}
	if(pmatches == true) {
		return in;	
	} else {
		in.setstate(std::ios::badbit);
		return in;	
	}
}

std::istream& operator>>(std::istream& in, StartsWith match) {
	std::string s;
	in >> s;
	for(unsigned int i = 0; i < match._match.length(); i++) {
		if(s[i] != match._match[i]) {
			in.setstate(std::ios::badbit);	
		}
	}
	return in;
}

std::istream& operator>>(std::istream& in, Anything match) {
	std::string s;
	in >> s;
	return in;	
}
