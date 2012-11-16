#include <iostream>
#include <cstdlib>
#include <string>
#include "AssocArray.h"
using namespace std;

AssocArray::AssocArray() {
_arr = NULL;
_size = 0;
}

AssocArray::~AssocArray() {
delete []_arr;
_arr = NULL;
_size = 0;
}

void AssocArray::insert(string key, int value) {
	for(int i = 0; i < size(); i++) {
		if(_arr[i].key == key) {
			cerr << "Error: Could not insert value to associative array: The key must be unique!" << endl;
			return;
		}
	}
inflate(1);
_arr[_size-1].key = key;
_arr[_size-1].value = value;
}

void AssocArray::remove(string key) {
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
		cerr << "Error: Could not find " << key << " key in associative array!" << endl;
	}
}

void AssocArray::clean() {
deflate(_size);
}

void AssocArray::inflate(int size) {
int newSize = _size + size;
AssocArrayEntry* newArray;
newArray = new AssocArrayEntry[newSize];
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

void AssocArray::deflate(int size) {
int newSize = _size - size;
AssocArrayEntry* newArray;
newArray = new AssocArrayEntry[newSize];
for(int i = 0; i < newSize; i++) {
newArray[i] = _arr[i];	
}
delete []_arr;
_arr = newArray;
_size = newSize;
}

int& AssocArray::operator[](string key) {
	int j = -1;
	for(int i = 0; i < size(); i++) {
		if(_arr[i].key == key) {
		j = i;
		break;
		}
	}
	if(j > -1) {
	return _arr[j].value;	
	} else {
		cerr << "Error: Could not find " << key << " key in associative array!" << endl;
	}
}

int AssocArray::size() {
return _size;	
}

void AssocArray::display() {
	cout << "AssocArray.display():" << endl;
	for(int i = 0; i < size(); i++) {
		cout << "##########" << endl << "key: " << _arr[i].key << endl << "value: " << _arr[i].value << endl << "##########" << endl;	
	}
}
