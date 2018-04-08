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
	tmp = tmp.substr(tmp.find_last_of("/") + 1, -3);
	if (tmp.length() > 3)
		tmp = tmp.erase(tmp.length() - 3);
	setLibrary(_gfxLibs, std::string("./lib"));
	setLibrary(_gamesLibs, std::string("./games"));
	auto it = std::find_if(_gfxLibs.begin(), _gfxLibs.end(),
		[tmp](const std::pair<std::string, std::string> &elem){ return elem.first == tmp; });
	if (it == _gfxLibs.end()) {
		_gfxLibs.push_back(std::pair<std::string, std::string>(tmp, _fname));
		std::rotate(_gfxLibs.begin(), _gfxLibs.begin() + 1, _gfxLibs.end());
	} else
		std::rotate(_gfxLibs.begin(), it, _gfxLibs.end());
	std::rotate(_gamesLibs.begin(), _gamesLibs.begin() + 1, _gamesLibs.end());
}

void	Loader::setLibrary(std::vector<std::pair<std::string, std::string>> &myLib, std::string path)
{
	if (auto dir = opendir(path.c_str())) { 
		while (auto f = readdir(dir)) {
			_libname = f->d_name;
			if (_libname.at(0) != '.' && _libname.find(".so") != std::string::npos) {
				std::string tmp = _libname.substr(_libname.find_last_of("/") + 1, -3);
				tmp = tmp.erase(tmp.length() - 3);
				myLib.push_back(std::pair<std::string, std::string>(tmp, path + "/" + _libname));
			}
		}
		closedir(dir);
	}
}

void	*Loader::loadDynamic(std::string &lname)
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

std::vector<std::pair<std::string, std::string>>	&Loader::getGfx()
{
	return _gfxLibs;
}

std::vector<std::pair<std::string, std::string>>	&Loader::getGames()
{
	return _gamesLibs;
}
