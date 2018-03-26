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
		std::cout << "Loading - Ncurses Library" << std::endl;
		initscr();
	}
	
	void	LibGFX::destroy()
	{
		endwin();
	}
	
	bool	LibGFX::checkKey(int a)
	{
		int c = getch();
		return (a == c);
	}

	void    display(std::pair<std::size_t, std::size_t> coord,
			DynLib::ENTITY, DynLib::Game &game)
	{
		mvprintw(coord.second, coord.first, "%c", game.getChar());
		refresh();
	}

	void    dispText(std::pair<std::size_t, std::size_t> coord,
			 std::string str)
	{
		mvprintw(coord.second, coord.first, str.c_str());
		refresh();
	}
}
