#pragma once
#include <stdexcept>
#include <string>
#include "numerical_exception.h"
/// \file calculation_exception.h
/// \brief A calculation exception implementation.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class calculation_exception
/// \brief A caluclation exception class inheriting from numerical_exception (because exc.cpp: 39-40 - throwing calculation_exception and catching numerical_exception).
class calculation_exception: public numerical_exception {
public:
	calculation_exception(); ///< A constructor.
	calculation_exception(std::string msg); ///< \brief A constructor with parameter.
	///< \param msg Error message.
	calculation_exception(std::string msg, std::string file, int line); ///< \brief A constructor with parameters.
	///< \param msg ///< Error message.
	///< \param file ///< File, where exception has been throwed.
	///< \param line ///< Line, where exception has been throwed.
	~calculation_exception() throw(); ///< \brief A destructor.
	const char* what() const throw(); ///< \brief A function returning error message.
	///< \return Error message.
};
