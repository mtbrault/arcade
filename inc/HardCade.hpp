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
#include <map>
#include "DynLib.hpp"
#include "Loader.hpp"

class   HardCade : public Loader {
public:
	HardCade(const std::string &first);
	~HardCade();
	void    run();
	void	loadLibs();
	void	putVector(std::vector<std::pair<std::string, std::string>> &myLib, int type);

private:

	enum	status_e {
		MENU,
		INGAME
	};

	void	modifName(const char c);
	void    listen();
	void    showMenu();
	int		showLibs();

	std::vector<std::pair<std::string, DynLib::IGfx *>>		libs;
	std::vector<std::pair<std::string, DynLib::IGame *>>		games;
	status_e						status;
	int								lk;
	std::string						name;
};

#endif
