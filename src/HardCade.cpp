//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Main program
//

#include <time.h>
#include <unistd.h>
#include <algorithm>
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
	}
	
}

void	HardCade::modifName(const char c)
{
	if (name.length() < 24)
		name += c;
}

int 	HardCade::showLibs()
{
	libs.front().second->dispText(0, 3, "Games:\t\t\t\tGraphics:");
	auto itg = games.begin();
	auto itl = libs.begin();
	int nb = 0;
	while (itg != games.end() || itl != libs.end()) {
		std::string tmp = "";
		if (itg != games.end()) {
			tmp += itg->first + "\t\t";
			++itg;
		} 
		if (itl != libs.end()) {
			tmp += itl->first;
			++itl;
		}
		libs.front().second->dispText(0, nb + 4, tmp);
		nb += 1;
	}
	return (nb + 5);
}

void    HardCade::showMenu()
{
	libs.front().second->dispText(0, 0, "HARDCADE");
	libs.front().second->dispText(0, 1, std::string("name: ") + name);
	int i = showLibs();
	libs.front().second->dispText(0, i + 1, "Press Enter to start, Escape to quit");
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
	if (c == 'w' || c == 'x') {
		libs.begin()->second->destroy();
		if (c == 'w')
			std::rotate(libs.begin(), libs.begin() + 1, libs.end());
		else
			std::rotate(libs.rbegin(), libs.rbegin() + 1, libs.rend());
		libs.begin()->second->init(0, 0);
		games.front().second->setLibGfx(*(libs.front().second));
	} else if (c == 'c' || c == 'v') {
		games.front().second->init();
		if (c == 'c')
			std::rotate(games.begin(), games.begin() + 1, games.end());
		else
			std::rotate(games.rbegin(), games.rbegin() + 1, games.rend());
		games.front().second->setLibGfx(*(libs.front().second));
	}
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
