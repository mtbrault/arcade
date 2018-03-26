//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Main program
//

#include "HardError.hpp"
#include "HardCade.hpp"

HardCade::HardCade(const std::string &first)
	: Loader(first), status(HardCade::status_e::MENU)
{
}

HardCade::~HardCade()
{
}

void    HardCade::loadLibs()
{
	std::vector<std::string>	gfxLib;
	std::vector<std::string>        gameLib;

	Loader::fillLibrary();
	gfxLib = Loader::getGfx();
	gameLib = Loader::getGames();
	putVector(gfxLib);
	putVector(gameLib);
}

void	HardCade::putVector(std::vector<std::string> &myLib)
{
	void	*ptr;

	for (auto it = myLib.begin() ; it != myLib.end() ; it++) {
		ptr = Loader::loadDynamic(*it);
		if (ptr != nullptr && myLib.size() == 3)
			libs.push_back((DynLib::Gfx*)ptr);
		else if (myLib.size() == 2)
			games.push_back((DynLib::Game*)ptr);
		else
			throw Error("Error while loading dynamicaly a library\n");
	}	
}

void    HardCade::showMenu()
{
}

void    HardCade::listen()
{
	
}

void    HardCade::run()
{
	if (!libs.size() || !games.size()) {
		std::cerr << "Error: No lib loaded" << std::endl;
		return ;
	}
	while (!libs.front()->checkKey(27)) {
		this->showMenu();
		while (status == HardCade::status_e::INGAME &&
		       !libs.front()->checkKey(27) && !games.front()->checkEnd()) {
			games.front()->aff();
			this->listen();
		}
		this->listen();
	}
}
