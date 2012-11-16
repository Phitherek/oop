#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
/// \file Map.h
/// \brief An implementation of associative array.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \struct MapEntry
/// \brief A structure, that defines an entry to associative array.
struct MapEntry {
map_key_type key; ///< A key identyfing an entry, of pre-defined type map_key_type.
map_value_type val; ///< A value of the entry, of pre-defined type map_value_type.
};

/// \class Map
/// \brief A class representing the associative array.
class Map {
private:
MapEntry *_tab; ///< An array of MapEntry structures.
int _size; ///< Size of the array.
public:
	Map(); ///< A constructor.
	~Map(); ///< A destructor.
	Map(Map &m); ///< \brief A copy constructor.
	///< \param m A Map object to be copied.
	Map& insert(map_key_type key, map_value_type val); ///< \brief A function, that inserts a value to associative array.
	///< \param key A key identyfing the entry.
	///< \param val A value of the entry.
	///< \return A reference to Map object.
	Map& print(std::string txt); ///< \brief A function, that outputs the associative array to output.
	///< \param txt Text, that is to be printed before an array.
	///< \return A reference to Map object.
	map_value_type& operator[](map_key_type key); ///< \brief A operator[], that can be used to access the values on associative array and to change their values and add new objects.
	///< \param key A key identyfing the entry.
	///< \return A reference to map_value_type, which is the value of the entry.
	map_value_type operator[](map_key_type key) const; ///< \brief A const operator[], that can be used to get the values from associative array.
	///< \param key A key identyfing the entry.
	///< \return A map_value_type containing the value of the entry.
	int contains(map_key_type key) const; ///< \brief A const function, that checks existence of certain key in the array.
	///< \param key A key to be checked.
	///< \return 1 if key exists, 0 otherwise.
};

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
