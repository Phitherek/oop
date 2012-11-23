#pragma once
#include <string>
/// \file Opt.h
/// \brief A general implementation of options.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class Opt
/// \brief A class representing options in general.

class Opt {
protected:
	int _pos; ///< A position of an option.
	int _pres; ///< 1 if option is present, 0 otherwise.
public:
	Opt(); ///< A constructor.
	~Opt(); ///< A destructor.
	virtual int check(char** argv, int argc); ///< \brief A virtual function that checks option existence in argv and sets its parameters accordingly.
	///< \param argv Argument array.
	///< \param argc Argument counter.
	///< \return A position of option.
	virtual std::string key(); ///< \brief A virtual function that returns the key of an option.
	///< \return Key of an option, of type std::string.
	int present(); ///< \brief A function that returns a value indicating (non-)existence of an option in argv.
	///< \return 1 if option is in argv, 0 otherwise.
};
