//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ncurses LibGFX class
//

#include "LibGFX.hpp"
#include <iostream>

namespace DynLib {

	extern "C" IGfx *getObj()
	{
		return new LibGFX;
	}

	LibGFX::LibGFX()
	{
	}
	
	void    LibGFX::init(int a, int b)
	{
		(void)a;
		(void)b;
		std::cout << "Loading - Ncurses Library" << std::endl;
		initscr();
	}
	
	void	LibGFX::destroy()
	{
		endwin();
	}
	
	int	LibGFX::getKey()
	{
		int c = getch();
		return (c);
	}

	int	LibGFX::getLastKey()
	{
		int c = getch();
		return (c);
	}

	void    display(std::pair<std::size_t, std::size_t> coord,
			DynLib::ENTITY, DynLib::IGame &game)
	{
		mvprintw(coord.second, coord.first, "%c", (char)game.getChar());
		refresh();
	}

	void    dispText(std::pair<std::size_t, std::size_t> coord,
			 std::string str)
	{
		mvprintw(coord.second, coord.first, str.c_str());
		refresh();
	}
}
