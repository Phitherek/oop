#pragma once
#include <stdexcept>
#include <string>
#include "numerical_exception.h"
#include "calculation_exception.h"
/// \file myexcept.h
/// \brief An implementation of exception handler
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class myexcept
/// \brief A unifying class for other exception.
class myexcept: public calculation_exception {
public:
	myexcept(); ///< A constructor.
	static void handler(std::string context); ///< \brief A handler for exceptions.
	///< \param context A context, in which exception was throwed.
	~myexcept() throw(); ///< \brief A destructor.
};
