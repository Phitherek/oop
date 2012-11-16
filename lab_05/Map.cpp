#include <iostream>
#include <cstdlib>
#include <string>
#include "Map.h"
using namespace std;

Map::Map() {
_tab = NULL;
_size = 0;
}

Map::~Map() {
	if(_tab != NULL) {
	delete[] _tab;
	_tab = NULL;	
	}
	_size = 0;
}

Map::Map(Map &m) {
_tab = new MapEntry[m._size];
_size = m._size;
for(int i = 0; i < m._size; i++) {
_tab[i] = m._tab[i];	
}
}

Map& Map::insert(map_key_type key, map_value_type val) {
MapEntry* newTab;
newTab = new MapEntry[_size+1];
for(int i = 0; i < _size; i++) {
newTab[i] = _tab[i];	
}
newTab[_size].key = key;
newTab[_size].val = val;
delete[] _tab;
_tab = newTab;
_size = _size+1;
return *this;
}

Map& Map::print(std::string txt) {
	std::cout << txt << std::endl;
for(int i = 0; i < _size; i++) {
	std::cout << _tab[i].key << ": " << _tab[i].val << std::endl;	
}
return *this;
}

map_value_type& Map::operator[](map_key_type key) {
int j = -1;
for(int i = 0; i < _size; i++) {
	if(_tab[i].key == key) {
	j = i;
	return _tab[i].val;	
	}
}
if(j == -1) {
MapEntry* newTab;
newTab = new MapEntry[_size+1];
for(int i = 0; i < _size; i++) {
newTab[i] = _tab[i];	
}
newTab[_size].key = key;
newTab[_size].val = 0;
delete[] _tab;
_tab = newTab;
_size = _size+1;
return _tab[_size-1].val;
}
}

map_value_type Map::operator[](map_key_type key) const {
int j = -1;
for(int i = 0; i < _size; i++) {
	if(_tab[i].key == key) {
	j = i;
	return _tab[i].val;	
	}
}
if(j == -1) {
	std::cerr << "Could not find the key: " << key << " in the array!" << std::endl;
	return 0;	
}
}

int Map::contains(map_key_type key) const {
	int j = -1;
	for(int i = 0; i < _size; i++) {
	if(_tab[i].key == key) {
	j = i;
	return 1;	
	}
}
if(j == -1) {
	return 0;	
}
}
