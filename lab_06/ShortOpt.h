#pragma once
#include "Opt.h"
/// \file ShortOpt.h
/// \brief An implementation of short options, inheriting from Opt.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class ShortOpt
/// \brief A class representing a short option that inherits from Opt.
class ShortOpt: public Opt {
protected:
	char _key; ///< A one-character key identyfing a short option.
public:
	ShortOpt(char c); ///< \brief A constructor with parameter.
	///< \param c Key of the option.
	int check(char** argv, int argc); ///< \brief A function, that checks option's existence in argv.
	///< \param argv Argument array.
	///< \param argc Argument counter.
	///< \return A position of option.
	std::string key(); ///< \brief A function returning the key of an option.
	///< \return The key of an option, of type std::string.
};
