//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Main program
//

#ifndef HARDCADE_HPP_
# define HARDCADE_HPP_

#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include "DynLib.hpp"
#include "Loader.hpp"

class   HardCade : public Loader {
public:
	HardCade(const std::string &first);
	~HardCade();
	void    run();
	void	loadLibs();
	void	putVector(std::vector<std::string> &myLib);

private:

	enum	status_e {
		MENU,
		INGAME
	};
	
	void    listen();
	void    showMenu();

	std::vector<DynLib::IGfx *>	libs;
	std::vector<DynLib::IGame *>	games;
	status_e			status;
};

#endif
