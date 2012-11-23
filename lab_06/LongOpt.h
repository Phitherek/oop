#pragma once
#include "Opt.h"
/// \file LongOpt.h
/// \brief An implementation of long options, inheriting from Opt.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class LongOpt
/// \brief A class representing a long option that inherits from Opt.
class LongOpt: public Opt {
private:
	std::string _key;
public:
	LongOpt(std::string s); ///< \brief A constructor with parameter.
	///< \param s Key of the option.
	~LongOpt(); ///< A destructor.
	int check(char** argv, int argc); ///< \brief A function, that checks option's existence in argv.
	///< \param argv Argument array.
	///< \param argc Argument counter.
	///< \return A reference to the modified LongOpt object.
	std::string key(); ///< \brief A function returning the key of an option.
	///< \return The key of an option, of type std::string.
};
