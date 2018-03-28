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
	if (_handle)
		if ((dlclose(_handle)) != 0) {
			std::string err("Library cannot be closed\n");
			std::cerr << err;
		}
}

void	Loader::fillLibrary()
{
        setLibrary(_gfxLibs, "./lib");
	setLibrary(_gamesLibs, "./games");
	auto itr = std::find(_gfxLibs.begin(), _gfxLibs.end(), _fname);
	if (itr != _gfxLibs.end()) _gfxLibs.erase(itr);
	_gfxLibs.insert(_gfxLibs.begin(), _fname);
}

void	Loader::setLibrary(std::vector<std::string> &myLib, std::string path)
{
	if (auto dir = opendir(path.c_str())) { 
		while (auto f = readdir(dir)) {
			_libname = f->d_name;
			if (_libname.at(0) != '.' && _libname.find(".so") != std::string::npos) {
				if (path == "./lib" || path == "./games")
					myLib.push_back(path + "/" + _libname);
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

std::vector<std::string>	&Loader::getGfx()
{
	return _gfxLibs;
}

std::vector<std::string>	&Loader::getGames()
{
	return _gamesLibs;
}
