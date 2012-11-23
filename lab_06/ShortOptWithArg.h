#pragma once
#include "ShortOpt.h"
#include "Arg.h"
/// \file ShortOptWithArg.h
/// \brief An implementation of short options with arguments, inheriting from ShortOpt.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class ShortOptWithArg
/// \brief A class representing a short option with argument that inherits from ShortOpt.
class ShortOptWithArg: public ShortOpt {
private:
	Arg _arg;
public:
	ShortOptWithArg(char c, Arg arg); ///< \brief A constructor with parameters.
	///< \param c A key of the option.
	///< \param arg A default argument..
	Arg arg(); ///< \brief A function returning the argument.
	///< \return An argument, of type Arg.
	int check(char** argv, int argc); ///< \brief A function, that checks if option and argument exist in argv.
	///< \param argv Argument array.
	///< \param argc Argument counter.
	///< \return A position of option.
};
