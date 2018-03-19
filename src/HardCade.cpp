//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Main program
//

#include "HardError.hpp"
#include "HardCade.hpp"

HardCade::HardCade(const std::string &first)
	: Loader(first)
{
}

HardCade::~HardCade()
{
}

void    HardCade::loadLibs()
{
	std::vector<std::string> gfxLib;
	Loader::fillLibrary();
	gfxLib = Loader::getGfx();
	for (auto it = gfxLib.begin() ; it != gfxLib.end() ; it++)
		Loader::loadDynamic(*it);
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
		while (!libs.front()->checkKey(27) && !games.front()->checkEnd()) {
			games.front()->aff();
			this->listen();
		}
		this->listen();
	}
}
