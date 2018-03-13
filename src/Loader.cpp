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
	_gfxLibs.push_back(_fname);
        setLibrary(_gfxLibs, "./lib");
	setLibrary(_gamesLibs, "./game");	
}

void	Loader::setLibrary(std::vector<std::string> &myLib, std::string path)
{
	if (auto dir = opendir(path.c_str())) { 
		while (auto f = readdir(dir)) {
			_libname = f->d_name;
			if (_libname.at(0) != '.' && _libname.find(".so") != std::string::npos)
				myLib.push_back(_libname);
		}
		closedir(dir);
	}	
}

void	Loader::loadDynamic(std::string lname)
{
	_handle = dlopen(lname.c_str(), RTLD_NOW);
	if (!_handle) {
		std::string err = dlerror();
		throw Error(err);
	}	
}

std::vector<std::string>	&Loader::getGfx()
{
	return _gfxLibs;
}

std::vector<std::string>	&Loader::getGames()
{
	return _gamesLibs;
}
