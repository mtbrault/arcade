//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ncurses LibGFX class
//

#include <iostream>
#include <curses.h>
#include <ncurses.h>
#include "LibGFX.hpp"

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

	void	LibGFX::clear()
	{
		clear();
	}
	
	void	LibGFX::refresh()
	{
		refresh();
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

	ENTITY LibGFX::getOnWin(int x, int y)
	{
		(void)x;
		(void)y;
		return (DynLib::ENTITY::PLAYER);
	}

	int	LibGFX::getLastKey()
	{
		int c = getch();
		return (c);
	}

	void    LibGFX::display(int x, int y, DynLib::ENTITY ent)
	{
		mvprintw(y, x, "%c", ent == NONE ? '0' : '1');
		refresh();
	}

	void    LibGFX::dispText(int x, int y, std::string str)
	{
		mvprintw(y, x, str.c_str());
		refresh();
	}
}
