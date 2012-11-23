#pragma once
#include <string>
/// \file Arg.h
/// \brief An implementation of option arguments.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class Arg
/// \brief A class representing option argument.
class Arg {
private:
	std::string _val;
public:
	Arg(std::string s); ///< \brief A constructor with parameter.
	///< \param s Value of the argument.
	Arg(); ///< A constructor.
	operator int(); ///< A converting operator int().
	operator std::string(); ///< A converting operator std::string().
	operator float(); ///< A converting operator float().
};
