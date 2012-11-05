#ifndef HASHARRAY_H
#define HASHARRAY_H
#include <string>
/// \file HashArray.h
/// \brief An implementation of hash array of integers
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \struct HashArrayEntry
/// \brief A structure representing a single entry in hash array of integers
struct HashArrayEntry {
	std::string key; ///< A key which identifies the entry.
	int value; ///< A value of the entry.
};

/// \class HashArray
/// \brief A class representing a hash array of integers
class HashArray {
private:
HashArrayEntry* _arr; ///< An array of HashArrayEntry structures which creates an hash array.
int _size; ///< Size of the array.
public:
	HashArray(); ///< A constructor for initializing.
	~HashArray(); ///< A destructor for cleaning up.
	void insert(std::string key, int value); ///< A function, that inserts a value to hash array.
	/// \param key A key which will identify the entry, of type std::string.
	/// \param value An int value to be inserted.
	void remove(std::string key); ///< A function, that removes a value from hash array.
	/// \param key A key that identifies the entry to be removed, of type std::string.
	void clean(); ///< A function, that clears the hash array.
	void inflate(int size); ///< A function, that increases the size of the array of entries.
	/// \param size A size by which the size of the array should be increased.
	void deflate(int size); ///< A function, that decreases the size of the array of entries.
	/// \param size A size by which the size of the array should be decreased.
	int& operator[](std::string key); ///< An operator: [], which can be used to extract integer values by their keys from hash array.
	/// \param key A key which identifies the entry.
	/// \return An int value associated with given key.
	int size(); ///< A function, that returns size of the hash array.
	/// \return Size of the hash array = Number of entries in the array, of type int.
	void display(); ///< A function, that displays the hash array on the cout.
};
#endif
