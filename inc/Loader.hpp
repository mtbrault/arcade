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
#include <dirent.h>
#include <vector>
#include <map>

class   Loader {
public:
	Loader(const std::string &fname);
	~Loader();

	void	fillLibrary();
        void	*loadDynamic(std::string lname);
	void	setLibrary(std::map<std::string, std::string> &, std::string path);
	std::map<std::string, std::string>  &getGfx();
	std::map<std::string, std::string>	&getGames();
private:
	void		*_handle;
	std::string	_fname;
	std::string	_libname;
	std::map<std::string, std::string> _gfxLibs;
	std::map<std::string, std::string> _gamesLibs;
};
