//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Pacman LibGame class
//

#include "LibGame.hpp"
#include <iostream>

namespace DynLib {

	extern "C" Game *getObj()
	{
		return new LibGame;
	}

	LibGame::LibGame()
	{
	}
	
	void    LibGame::aff()
	{
		std::cout << "Loading - Pacman Game" << std::endl;
	}
	
	bool	LibGame::checkEnd()
	{
		return true;
	}
}
