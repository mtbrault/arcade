//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Lib Loader
//

#include "HardError.hpp"
#include "Loader.hpp"

Loader::Loader(const std::string &fname)
	: _fname(fname)
{
	_handle = dlopen(_fname.c_str(), RTLD_NOW);
	if (!_handle) {
		std::string err = dlerror();
		throw Error(err);
	}
}

Loader::~Loader() 
{
	if ((dlclose(_handle)) != 0) {
		std::string err("Library cannot be closed\n");
		std::cerr << err;
	}
}

