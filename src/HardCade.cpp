//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Main program
//

#include <time.h>
#include <unistd.h>
#include "HardError.hpp"
#include "HardCade.hpp"

HardCade::HardCade(const std::string &first)
	: Loader(first), status(HardCade::status_e::MENU), lk(0), name("")
{
}

HardCade::~HardCade()
{
}

void    HardCade::loadLibs()
{
	std::map<std::string, std::string>	gfxLib;
	std::map<std::string, std::string>	gameLib;

	Loader::fillLibrary();
	gfxLib = Loader::getGfx();
	gameLib = Loader::getGames();
	putVector(gfxLib, 1);
	putVector(gameLib, 2);
}

void	HardCade::putVector(std::map<std::string, std::string> &myLib, int type)
{
	void	*ptr;

	for (auto it = myLib.begin() ; it != myLib.end() ; ++it) {
		ptr = Loader::loadDynamic(it->second);
		if (ptr != nullptr && type == 1)
			libs.push_back(std::pair<std::string, DynLib::IGfx*>(it->first, (DynLib::IGfx*)ptr));
		else if (type == 2)
			games.push_back(std::pair<std::string, DynLib::IGame*>(it->first, (DynLib::IGame*)ptr));
		else
			throw Error("Error while loading dynamicaly a library\n");
	}this->listen();
	
}

void	HardCade::modifName(const char c)
{
	if (name.length() < 12)
		name += c;
}

void    HardCade::showMenu()
{
	libs.front().second->dispText(0, 0, "HARDCADE");
	libs.front().second->dispText(0, 1, std::string("name: ") + name);
	libs.front().second->dispText(0, 2, "Games:\t\t\tGraphics:");
	libs.front().second->dispText(0, 4, "Press Enter to start, escape to quit");
	lk = libs.front().second->getKey();
	if (lk == 13) {
		//for (i ; libs. ||  ; i += 1)
		games.front().second->init();
		games.front().second->setLibGfx(*(libs.front().second));
		libs.front().second->clear();
		status = HardCade::status_e::INGAME;
	} else if ((lk >= 'a' && lk <= 'z') || (lk >= 'A' && lk <= 'Z')) {
		modifName(lk);
	} else if (lk == 263 && name.length() > 0)
		name.pop_back();
}

void	HardCade::listen()
{
	int c = libs.front().second->getKey();
	(void)c;
	/*Change libs, Games, Quit, etc..*/
	/* GetKey first checked here then getLastKey ingame */
	/* Only one getch */
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
	libs.front().second->init(0, 0);
	while (lk != 27) {
		this->showMenu();
		while (status == HardCade::status_e::INGAME && !games.front().second->checkEnd()) {
			this->listen();
			games.front().second->aff();
			usleep(250000);
		}
		libs.front().second->clear();
	}
	libs.front().second->destroy();
	/*
	this->showMenu();
	while (1)
		libs.front()->display(0, 0, DynLib::ENTITY::PLAYER);*/
	
}
