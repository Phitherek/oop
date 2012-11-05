#include <iostream>
#include <cstdlib>
#include <string>
#include "HashArray.h"
using namespace std;

HashArray::HashArray() {
_arr = NULL;
_size = 0;
}

HashArray::~HashArray() {
delete []_arr;
_arr = NULL;
_size = 0;
}

void HashArray::insert(string key, int value) {
	for(int i = 0; i < size(); i++) {
		if(_arr[i].key == key) {
			cerr << "Error: Could not insert value to hash array: The key must be unique!" << endl;
			return;
		}
	}
inflate(1);
_arr[_size-1].key = key;
_arr[_size-1].value = value;
}

void HashArray::remove(string key) {
	int j = -1;
	for(int i = 0; i < size(); i++) {
		if(_arr[i].key == key) {
		j = i;
		break;
		}
	}
	if(j > -1) {
		for(int i = j; i < size()-1; i++) {
		_arr[i] = _arr[i+1];
		}
		deflate(1);
	} else {
		cerr << "Error: Could not find " << key << " key in hash array!" << endl;
	}
}

void HashArray::clean() {
deflate(_size);
}

void HashArray::inflate(int size) {
int newSize = _size + size;
HashArrayEntry* newArray;
newArray = new HashArrayEntry[newSize];
for(int i = 0; i < _size; i++) {
newArray[i] = _arr[i];	
}
for(int i = _size; i < newSize; i++) {
newArray[i].key = "";
newArray[i].value = 0;
}
delete []_arr;
_arr = newArray;
_size = newSize;
}

void HashArray::deflate(int size) {
int newSize = _size - size;
HashArrayEntry* newArray;
newArray = new HashArrayEntry[newSize];
for(int i = 0; i < newSize; i++) {
newArray[i] = _arr[i];	
}
delete []_arr;
_arr = newArray;
_size = newSize;
}

int& HashArray::operator[](string key) {
	int j = -1;
	for(int i = 0; i < size(); i++) {
		if(_arr[i].key == key) {
		j = i;
		break;
		}
	}
	if(j > -1) {
	return _arr[i].value;	
	} else {
		cerr << "Error: Could not find " << key << " key in hash array!" << endl;
	}
}

int HashArray::size() {
return _size;	
}

void HashArray::display() {
	cout << "HashArray.display():" << endl;
	for(int i = 0; i < size(); i++) {
		cout << "##########" << endl << "key: " << _arr[i].key << endl << "value: " << _arr[i].value << endl << "##########" << endl;	
	}
}
