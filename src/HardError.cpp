//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Error Class
//

#include "HardError.hpp"

Error::Error(std::string const &message)
	: _message(message)
{
}

Error::~Error() throw()
{
}

const char *Error::what() const throw()
{
	return _message.c_str();
}
