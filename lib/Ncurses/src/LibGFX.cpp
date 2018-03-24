//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ncurses LibGFX class
//

#include "LibGFX.hpp"
#include <iostream>

namespace DynLib {

	extern "C" Gfx *getObj()
	{
		return new LibGFX;
	}

	LibGFX::LibGFX()
	{
	}
	
	void    LibGFX::init()
	{
		std::cout << "je suis ncurses" << std::endl;
	}
	bool	LibGFX::checkKey(int a)
	{
		(void) a;
		return true;
	}
}
