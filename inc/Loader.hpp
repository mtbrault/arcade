//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Lib Loader
//

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <iostream>
#include <string>

class   Loader {
public:
	Loader(const std::string &fname);
	~Loader();

private:
	void		*_handle;
	std::string	_fname;
};
