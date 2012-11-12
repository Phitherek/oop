#ifndef ASSOCARRAY_H
#define ASSOCARRAY_H
#include <string>
/// \file AssocArray.h
/// \brief An implementation of associative array of integers
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \struct AssocArrayEntry
/// \brief A structure representing a single entry in associative array of integers
struct AssocArrayEntry {
	std::string key; ///< A key which identifies the entry.
	int value; ///< A value of the entry.
};

/// \class AssocArray
/// \brief A class representing an associative array of integers
class AssocArray {
private:
AssocArrayEntry* _arr; ///< An array of AssocArrayEntry structures which creates an associative array.
int _size; ///< Size of the array.
public:
	AssocArray(); ///< A constructor for initializing.
	~AssocArray(); ///< A destructor for cleaning up.
	AssocArray(AssocArray& aa); ///< A copy constructor.
	void insert(std::string key, int value); ///< \brief A function, that inserts a value to associative array.
	///< \param key A key which will identify the entry, of type std::string.
	///< \param value An int value to be inserted.
	void remove(std::string key); ///< \brief A function, that removes a value from associative array.
	///< \param key A key that identifies the entry to be removed, of type std::string.
	void clean(); ///< A function, that clears the associative array.
	void inflate(int size); ///< \brief A function, that increases the size of the array of entries.
	///< \param size A size by which the size of the array should be increased.
	void deflate(int size); ///< \brief A function, that decreases the size of the array of entries.
	///< \param size A size by which the size of the array should be decreased.
	int& operator[](std::string key); ///< \brief An operator: [], which can be used to extract integer values by their keys from associative array.
	///< \param key A key which identifies the entry.
	///< \return An int value associated with given key.
	int size(); ///< \brief A function, that returns size of the associative array.
	///< \return Size of the associative array = Number of entries in the array, of type int.
	void display(); ///< A function, that displays the associative array on the cout.
	AssocArray& sumfields(); ///< A function, that inserts a sum of previous fields to next field.
};
#endif
