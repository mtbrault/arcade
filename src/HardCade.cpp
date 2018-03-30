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
	std::vector<std::string>	gameLib;

	Loader::fillLibrary();
	gfxLib = Loader::getGfx();
	gameLib = Loader::getGames();
	putVector(gfxLib, 1);
	putVector(gameLib, 2);
}

void	HardCade::putVector(std::vector<std::string> &myLib, int type)
{
	void	*ptr;

	for (auto it = myLib.begin() ; it != myLib.end() ; it++) {
		ptr = Loader::loadDynamic(*it);
		if (ptr != nullptr && type == 1)
			libs.push_back((DynLib::IGfx*)ptr);
		else if (type == 2)
			games.push_back((DynLib::IGame*)ptr);
		else
			throw Error("Error while loading dynamicaly a library\n");
	}
	
}

void    HardCade::showMenu()
{
	games.front()->init();
	games.front()->setLibGfx(*(libs.front()));
	status = HardCade::status_e::INGAME;
}

void    HardCade::listen()
{
	
}

void    HardCade::run()
{
	if (!games.size()) {
		throw Error("Error: No game loaded.");
		return ;
	} else if (!libs.size()) {
		throw Error("Error: No graphic lib loaded.");
		return ;
	}
	while (libs.front()->getLastKey() != 27) {
		this->showMenu();	
		while (status == HardCade::status_e::INGAME &&
		       libs.front()->getLastKey() != 27 && !games.front()->checkEnd()) {
			printf("sqdqsd\n");
			games.front()->aff();
			this->listen();
		}
		this->listen();
	}
	/*libs.front()->init(0, 0);
	this->showMenu();
	while (1)
		libs.front()->display(0, 0, DynLib::ENTITY::PLAYER);
	libs.front()->destroy();*/
	
	
}
