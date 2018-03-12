//
// EPITECH PROJECT, 2018
// 201yams_2017
// File description:
// Errors header
//

#ifndef ERROR_HPP_
# define ERROR_HPP_

#include <iostream>

class	Error : public std::exception {
public:
	Error(std::string const &message);
	~Error() throw();

	const char *what() const throw();
	std::string _message;
};

#endif	/* !ERROR_HPP_ */
