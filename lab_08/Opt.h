#pragma once
#include <string>
#include <exception>
/// \file Opt.h
/// \brief A general implementation of options and exceptions.
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
	virtual int check(const char** argv, int argc); ///< \brief A virtual function that checks option existence in argv and sets its parameters accordingly.
	///< \param argv Argument array.
	///< \param argc Argument counter.
	///< \return A position of option.
	virtual std::string key(); ///< \brief A virtual function that returns the key of an option.
	///< \return Key of an option, of type std::string.
	int present(); ///< \brief A function that returns a value indicating (non-)existence of an option in argv.
	///< \return 1 if option is in argv, 0 otherwise.
};

/// \namespace opt
/// \brief A namespace for exception classes from Opt.h.
namespace opt {
/// \class invalid_argument
/// \brief A class implementing the Invalid Argument exception, inheriting from std::exception.
class invalid_argument: public std::exception {
	private:
		std::string _option;
		std::string _badarg;
	public:
		invalid_argument(); ///< A constructor.
		invalid_argument(std::string option, std::string badarg); ///< \brief A constructor with parameter.
		///< \param option Option key.
		///< \param badarg A bad argument.
		~invalid_argument() throw(); ///< A destructor, as needed by std::exception.
		const char* what() const throw(); ///< \brief A function returning a message describing what has happened, as needed by std::exception.
		///< \return A message describing what has happened.
	};
/// \class unknown_option
/// \brief A class implementing the Unknown Option exception, inheriting from std::exception.
	class unknown_option: public std::exception {
	private:
		std::string _what;
	public:
		unknown_option(); ///< A constructor.
		unknown_option(std::string s); ///< \brief A constructor with parameter.
		///< \param s A message describing what has happened.
		~unknown_option() throw(); ///< A destructor, as needed by std::exception.
		const char* what() const throw(); ///< \brief A function returning a message describing what has happened, as needed by std::exception.
		///< \return A message describing what has happened.	
	};	
};
