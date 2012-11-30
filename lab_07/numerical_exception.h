#pragma once
#include <stdexcept>
#include <string>
/// \file numerical_exception.h
/// \brief A numerical exception implementation.
/// \author Piotr Żurek
/// \date 2012
/// \version 0.1

/// \class numerical_exception
/// \brief A numerical exception class inheriting from std::runtime_error (because exc.cpp: 33-34 - throwing numerical_exception and catching std::runtime_error).
class numerical_exception: public std::runtime_error {
protected:
	static std::string _msg; ///< Error message.
	static std::string _file; ///< File, where exception has been throwed.
	static int _line; ///< Line, where exception has been throwed.
public:
	numerical_exception(); ///< \brief A constructor.
	numerical_exception(std::string msg); ///< \brief A constructor with parameter.
	///< \param msg Error message.
	~numerical_exception() throw(); ///< \brief A destructor.
	numerical_exception(std::string msg, std::string file, int line); ///< \brief A constructor with parameters.
	///< \param msg ///< Error message.
	///< \param file ///< File, where exception has been throwed.
	///< \param line ///< Line, where exception has been throwed.
	const char* what() const throw(); ///< \brief A function returning error message.
	///< \return Error message.
};
