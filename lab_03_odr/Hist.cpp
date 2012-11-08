#include <iostream>
#include <cstdlib>
#include "Hist.h"
using namespace std;

Hist::Hist(int n, float min, float max) {
_n = n;
_min = min;
_max = max;
_bins = new float[n];
for(int i = 0; i < n; i++) {
_bins[i] = 0.;	
}
}

Hist::~Hist() {
_n = 0;
_min = 0;
_max = 0;
delete []_bins;
_bins = NULL;
}

Hist Hist::fill(int n) {
	if(n >= _max || n < _min) {
	cerr << "Value not in range!" << endl;
	return *this;	
	}
	_bins[n-static_cast<int>(_min)]++;
	return *this;
}

void Hist::print(Hist h) {
	cout << "Histogram of n-bins: " << h._n << " from-to: [" << h._min << "-" << h._max << ") bins content:";
	for(int i = 0; i < h._n; i++) {
	cout << h._bins[i] << " ";	
	}
	cout << endl;
}

const Hist Hist::add(const Hist h1, const Hist h2, int mult1, int mult2) {
Hist h3(h1._n, h1._min, h1._max);
for(int i = 0; i < h1._n; i++) {
h3._bins[i] = mult1*h1._bins[i] + mult2*h2._bins[i];	
}
return h3;
}

float Hist::integral() {
float sum = 0;
for(int i = 0; i < _n; i++) {
sum += _bins[i];	
}
return sum;
}

Hist Hist::scale(float f) {
	for(int i = 0; i < _n; i++) {
	_bins[i] *= f;	
	}
	return *this;
}

Hist Hist::normalize(float f) {
float sum = integral();
float mult = f/sum;
for(int i = 0; i < _n; i++) {
_bins[i] *= mult;	
}
return *this;
}

Hist Hist::normalize() {
float f = 1.;
float sum = integral();
float mult = f/sum;
for(int i = 0; i < _n; i++) {
_bins[i] *= mult;	
}
return *this;
}

float Hist::binContent(int i) {
return _bins[i];	
}
