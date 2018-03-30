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
		std::cout << "Graphic lib \"Ncurses\" loaded." << std::endl;
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
		printf("HESDASD\n");
		mvprintw(y, x, "%c", ent == NONE ? '0' : '1');
		printf("HESDASD\n");
		refresh();
	}

	void    LibGFX::dispText(int x, int y, std::string str)
	{
		mvprintw(y, x, "%s", str.c_str());
		printf("abcdef");
		refresh();
	}
}
