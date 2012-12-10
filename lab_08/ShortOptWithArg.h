#pragma once
#include "ShortOpt.h"
#include "Arg.h"
#include "Validation.h"
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
	Validation* _checker;
public:
	ShortOptWithArg(char c, Arg arg); ///< \brief A constructor with parameters.
	///< \param c A key of the option.
	///< \param arg A default argument.
	ShortOptWithArg(char c, Arg arg, Validation* checker); ///< \brief A constructor with parameters.
	///< \param c A key of the option.
	///< \param arg A default argument.
	///< \param checker A reference to an object of the Validation class that implements type checking.
	~ShortOptWithArg(); ///< A destructor.
	Arg arg(); ///< \brief A function returning the argument.
	///< \return An argument, of type Arg.
	int check(const char** argv, int argc); ///< \brief A function, that checks if option and argument exist in argv.
	///< \param argv Argument array.
	///< \param argc Argument counter.
	///< \return A position of option.
};
