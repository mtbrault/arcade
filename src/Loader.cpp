//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Lib Loader
//

#include "HardError.hpp"
#include "Loader.hpp"
#include <algorithm>

Loader::Loader(const std::string &fname)
	: _fname(fname)
{
}

Loader::~Loader() 
{
	if (_handle) {
		if ((dlclose(_handle)) != 0) {
			std::string err("Library cannot be closed\n");
			std::cerr << err;
		}
	}
}

void	Loader::fillLibrary()
{
	std::string tmp = _fname;
	tmp = tmp.substr(0, -3);
	setLibrary(_gfxLibs, "./lib");
	setLibrary(_gamesLibs, "./games");
/*	if (_gamesLibs.find(tmp) == _gamesLibs.end())
		_gamesLibs[tmp]= _fname;*/
}

void	Loader::setLibrary(std::map<std::string, std::string> &myLib, std::string path)
{
	if (auto dir = opendir(path.c_str())) { 
		while (auto f = readdir(dir)) {
			_libname = f->d_name;
			if (_libname.at(0) != '.' && _libname.find(".so") != std::string::npos) {
				myLib[_libname.substr(0, -3)] = path + "/" + _libname;
			}
		}
		closedir(dir);
	}	
}

void	*Loader::loadDynamic(std::string lname)
{
	void	*(*ptr)(void);

	_handle = dlopen(lname.c_str(), RTLD_LAZY);
	if (!_handle) {
		std::string	err = dlerror();
		throw Error(err);
	}
        ptr = (void *(*)(void)) dlsym(_handle, "getObj");
	return (ptr());
}

std::map<std::string, std::string>	&Loader::getGfx()
{
	return _gfxLibs;
}

std::map<std::string, std::string>	&Loader::getGames()
{
	return _gamesLibs;
}
