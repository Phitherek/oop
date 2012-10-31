#ifndef _tab_h
#define _tab_h
//! \file tab.h
//! \brief An implementation of a structure, that simplifies operations on two-dimensional arrays.
//! \author Piotr Żurek
//! \date 2012

//! \typedef TabRange
//! \brief A typedef to an array of 4 integers, that represents a range in two-dimensional array.
//!
//! This typedef defines a type of 4 integers, which represent a range in two-dimensional array. First two integers are indexes of the starting field in the range, the two other ones are the limits of the range.
//! \warning The limits of the range are not included in the range itself.
typedef int TabRange[4];

//! \struct Tab
//! \brief A structure, that represents two-dimensional array of integers.
struct Tab {
int* tab; //!< A pointer to the beginning of one-dimensional array of integers.
int x; //!< Number of rows in the array.
int y; //!< Number of columns in the array.
};
//! \fn getindex(int rowsize, int x, int y)
//! \brief A function, that converts two-dimensional indexes for one-dimensional representation of array.
//! \param rowsize Size of a row in two-dimensional array.
//! \param x Index of a row.
//! \param y Index of a column.
//! \return Index of the element in one-dimensional array.
int getindex(int rowsize, int x, int y);
//! \fn init(Tab* t, int x, int y, int initval)
//! \brief Function initialising Tab structure.
//!
//! This function initialises Tab structure with given array size and initial value.
//! \param t A pointer to the Tab structure, where initialised data is returned.
//! \param x Number of rows in the array.
//! \param y Number of columns in the array.
//! \param initval Initial value of each element of the array.
void init(Tab* t, int x, int y, int initval);
//! \fn diag(Tab* t, int val)
//! \brief Function setting diagonal value.
//!
//! This function sets a given value on the main diagonal of the array.
//! \param t A pointer to a Tab structure that represents an array.
//! \param val A value to be set on the diagonal.
void diag(Tab* t, int val);
//! \fn set(Tab* t, int x, int y, int val)
//! \brief Function setting a value in the array.
//!
//! This function sets a given value on a given place in the array.
//! \param t A pointer to a Tab structure that represents an array.
//! \param x Index of a row.
//! \param y Index of a column.
//! \param val A value to be set.
void set(Tab* t, int x, int y, int val);
//! \fn set_part(Tab* t, TabRange range, int val)
//! \brief Function setting a value in the given part of an array.
//!
//! This function sets a given value in the given range in the array.
//! \param t A pointer to a Tab structure that represents an array.
//! \param range A TabRange describing a range where the given value should be set.
//! \param val A value to be set.
void set_part(Tab* t, TabRange range, int val);
//! \fn print(Tab* t)
//! \brief Function, that prints an array.
//!
//! This function prints out an array contained by the Tab structure.
//! \param t A pointer to a Tab structure that represents an array.
void print(Tab* t);
//! \fn insert(Tab* source, Tab* dest, TabRange range)
//! \brief Function inserting one array into another.
//!
//! This function inserts a given array represented by a Tab structure into another array of the same type in given TabRange.
//! \param source A pointer to a Tab structure that represents an array to be inserted.
//! \param dest A pointer to a Tab structure that represents an array where the another one should be inserted.
//! \param range A TabRange describing range, where the array should be inserted.
//! \warning Function does not check sizes. Misuse can lead to errors.
void insert(Tab* source, Tab* dest, TabRange range);
//! \fn extract(Tab* t, TabRange range)
//! \brief Function extracting a part from the array.
//!
//! This function extracts a given range from a given array as a new array.
//! \param t A pointer to a Tab structure that represents an array.
//! \param range A TabRange describing a range, that is to be extracted as a new array.
//! \return A pointer to a Tab structure that represents extracted array.
//! \warning Function does not check sizes. Misuse can lead to errors.
Tab* extract(Tab* t, TabRange range);
//! \fn clean(Tab* t)
//! \brief Function cleaning Tab structure.
//!
//! This function cleans the given Tab structure and frees the memory.
//! \param t A pointer to a Tab structure that is to be cleaned and freed.
void clean(Tab* t);
#endif
