#ifndef _PARSINGUTILS_H
#define _PARSINGUTILS_H
/// \file ParsingUtils.h
/// \brief A set of useful parsing utilities.
/// \author Piotr Żurek
/// \date 2013
/// \version 0.1
#include <string>
#include <iostream>

/// \class Exact
/// \brief A class, that searches for an exact word match.
class Exact {
private:
	std::string _match;
public:
	Exact(std::string match); ///< \brief A constructor with parameter.
	///< \param match A string to match.
	~Exact(); ///< A destructor.
	friend 	std::istream& operator>>(std::istream& stream, Exact check); ///< \brief A friend operator>> for streams.
	///< \param stream An input stream.
	///< \param check A checking object.
	///< \return An input stream or failbit on error.
};

/// \class Contains
/// \brief A class, that searches for a certain pattern in the word.
class Contains {
private:
	std::string _match;
public:
	Contains(std::string match); ///< \brief A constructor with parameter.
	///< \param match A string to match.
	~Contains(); ///< A destructor.
	friend 	std::istream& operator>>(std::istream& stream, Contains check); ///< \brief A friend operator>> for streams.
	///< \param stream An input stream.
	///< \param check A checking object.
	///< \return An input stream or failbit on error.
};

/// \class StartsWith
/// \brief A class, that searches for a certain pattern at the beginning of the word.
class StartsWith {
private:
	std::string _match;
public:
	StartsWith(std::string match); ///< \brief A constructor with parameter.
	///< \param match A string to match.
	~StartsWith(); ///< A destructor.
	friend 	std::istream& operator>>(std::istream& stream, StartsWith check); ///< \brief A friend operator>> for streams.
	///< \param stream An input stream.
	///< \param check A checking object.
	///< \return An input stream or failbit on error.
};

/// \class Anything
/// \brief A class, that accepts everything.

class Anything {
public:
	friend std::istream& operator>>(std::istream& stream, Anything check); ///< \brief A friend operator>> for streams.
	///< \param stream An input stream.
	///< \param check A checking object.
	///< \return An input stream or failbit on error.
};
#endif
