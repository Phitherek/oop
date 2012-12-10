#pragma once
#include "Opt.h"
#include "ShortOpt.h"
#include "LongOpt.h"
#include "ShortOptWithArg.h"
#include "Arg.h"
#include "Validation.h"
#include <exception>
#include <string>
/// \file Options.h
/// \brief An implementation of option container.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class Options
/// \brief A class representing a container for different options.
class Options {
private:
	ShortOpt** _container;
	int _size;
public:
	void add(ShortOpt* object); ///< \brief A function adding an object to the container.
	///< \param object An object to be added to the container.
	std::string operator[](int idx); ///< \brief A operator[] returning a std::string with information about certain object.
	///< \param idx Index of the object.
	///< \return A std::string with information about the object.
	Options(); ///< A constructor.
	~Options(); ///< A destructor.
	void parse(const char** argv, int argc); ///< \brief A function, that parses command line in search for options.
	///< \param argv Argument array.
	///< \param argc Argument counter.
};
