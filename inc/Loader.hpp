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

class   Loader {
public:
	Loader(const std::string &fname);
	~Loader();

	void	fillLibrary();
        void	*loadDynamic(std::string lname);
	void	setLibrary(std::vector<std::string> &, std::string path);
	std::vector<std::string>        &getGfx();
	std::vector<std::string>	&getGames();
private:
	void		*_handle;
	std::string	_fname;
	std::string	_libname;
	std::vector<std::string> _gfxLibs;
	std::vector<std::string> _gamesLibs;
};
