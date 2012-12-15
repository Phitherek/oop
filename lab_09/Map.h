#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
/// \file Map.h
/// \brief An implementation of a template of associative array.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \struct MapEntry
/// \brief A template of an entry in the associative array.
template<typename T, typename U> struct MapEntry {
	T key; ///< A key identyfing the value, parametrized by T.
	U value; ///< The value, parametrized by U.
};

/// \class Map
/// \brief A template of the associative array.
template<typename T, typename U> class Map {
private:
	MapEntry<T, U>* _table;
	int _size;
public:
	Map(); ///< A constructor.
	~Map(); ///< A destructor.
	Map<T, U>& insert(T key, U value); ///< \brief A function inserting a value to associative array.
	///< \param key Key identyfing the value, parametrized by T.
	///< \param value The value, parametrized by U.
	///< \return A reference to the changed Map<T, U> object.
	void print(std::string str); ///< \brief A function printing out the associative array with a given description.
	///< \param str A description.
	U& operator[](T key); ///< \brief An operator[] that can be used to print/change the value under the given key.
	///< \param key Key identyfing the value, parametrized by T.
	///< \return A reference to the value, parametrized by U.
	U operator[](T key) const; ///< \brief A const operator[] that can be used to print the value under the given key.
	///< \param key Key identyfing the value, parametrized by T.
	///< \return The value, parametrized by U.
	int contains(T key) const; ///< \brief Function checking certain key' s existence in the array.
	///< \param key Key identyfing the value, parametrized by T.
	///< \return 1 if value with that key is in the array, 0 otherwise.
};

template<typename T, typename U> Map<T, U>::Map() {
_table = NULL;
_size = 0;
}

template<typename T, typename U> Map<T, U>::~Map() {
	if(_table != NULL) {
	delete[] _table;	
	}
	_table = NULL;
	_size = 0;
}

template<typename T, typename U> Map<T, U>& Map<T, U>::insert(T key, U value) {
	int inTab = 0;
	if(_table != NULL) {
		for(int i = 0; i < _size; i++) {
			if (_table[i].key == key) {
			_table[i].value = value;
			inTab = 1;
			break;
			}
		}
	}
	if(inTab == 0) {
	int newSize = _size+1;
	MapEntry<T, U>* newTable = NULL;
	newTable = new MapEntry<T, U>[newSize];
	for(int i = 0; i < _size; i++) {
	newTable[i] = _table[i];	
	}
	newTable[newSize-1].key = key;
	newTable[newSize-1].value = value;
	delete[] _table;
	_table = newTable;
	_size = newSize;
	}
	return *this;
}

template<typename T, typename U> void Map<T, U>::print(std::string str) {
	for(int i = 0; i < _size; i++) {
		std::cout << str << " k: " << _table[i].key << " v: " << _table[i].value << std::endl;	
	}
}

template<typename T, typename U> U& Map<T, U>::operator[](T key) {
	int tabIdx = -1;
	if(_table != NULL) {
		for(int i = 0; i < _size; i++) {
			if (_table[i].key == key) {
			tabIdx = i;
			break;
			}
		}
		if(tabIdx != -1) {
			return _table[tabIdx].value;	
		} else {
	int newSize = _size+1;
	MapEntry<T, U>* newTable = NULL;
	newTable = new MapEntry<T, U>[newSize];
	for(int i = 0; i < _size; i++) {
	newTable[i] = _table[i];	
	}
	newTable[newSize-1].key = key;
	delete[] _table;
	_table = newTable;
	_size = newSize;
	return _table[_size-1].value;
		}
	} else {
		int newSize = _size+1;
	MapEntry<T, U>* newTable = NULL;
	newTable = new MapEntry<T, U>[newSize];
	for(int i = 0; i < _size; i++) {
	newTable[i] = _table[i];	
	}
	newTable[newSize-1].key = key;
	delete[] _table;
	_table = newTable;
	_size = newSize;
	return _table[_size-1].value;
	}
}

template<typename T, typename U> U Map<T, U>::operator[](T key) const {
	int tabIdx = -1;
	if(_table != NULL) {
		for(int i = 0; i < _size; i++) {
			if (_table[i].key == key) {
			tabIdx = i;
			break;
			}
		}
		if(tabIdx != -1) {
			return _table[tabIdx].value;	
		} else {
			throw std::invalid_argument("Klucz nieodpowiedni");
		}
	} else {
	throw std::invalid_argument("Klucz nieodpowiedni");
	}
}

template<typename T, typename U> int Map<T, U>::contains(T key) const {
	int inTab = 0;
	if(_table != NULL) {
		for(int i = 0; i < _size; i++) {
			if (_table[i].key == key) {
			inTab = 1;
			break;
			}
		}
	}
	return inTab;
}
