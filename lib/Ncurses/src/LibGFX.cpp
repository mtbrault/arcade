//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ncurses LibGFX class
//

#include <iostream>
#include <curses.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <term.h>
#include <termios.h>
#include "LibGFX.hpp"

namespace DynLib {

	extern "C" IGfx *getObj()
	{
		return new LibGFX;
	}

	LibGFX::LibGFX()
		:_lk(0)
	{
		std::cout << "Graphic lib \"Ncurses\" loaded." << std::endl;
	}
	
	void            LibGFX::nonCanon(const char reset)                                                               
	{                                                                     
        struct termios newt;
        char     *term = getenv("TERM");
        int ret;
        if (reset == 1) {
                ioctl(0, TCSETS, &_oldt);
                return;
        }
        if (setupterm(term, 1, &ret) == ERR)
                throw std::exception();
        if (ioctl(0, TCGETS, &_oldt) == -1 || ioctl(0, TCGETS, &newt) == -1)
                throw std::exception();
        newt = _oldt;
        newt.c_lflag &= ~ECHO;
        newt.c_lflag &= ~ICANON;
        newt.c_cc[VMIN] = 0;
        newt.c_cc[VTIME] = 0;
        if (ioctl(0, TCSETS, &newt) == -1)
                throw std::exception();
	}

	void    LibGFX::init(int a, int b)
	{
		(void)a;
		(void)b;
  		if (!initscr() || 
           	keypad(stdscr, true) == ERR ||
        	nonl() == ERR ||
            noecho() == ERR ||
            cbreak() == ERR ||
            curs_set(0) == ERR)
                throw std::exception();                                                          
        nonCanon(0);
	}

	void	LibGFX::clear()
	{
		clear();
	}
	
	void	LibGFX::refresh()
	{
		//refresh();
	}

	void	LibGFX::destroy()
	{
		nonCanon(1);
        curs_set(1);
        echo();
        keypad(stdscr, false);
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
		//printf("Get -> %d\n", c);
		if (c != _lk)
			_lk = c;
		return (_lk);
	}

	void    LibGFX::display(int x, int y, DynLib::ENTITY ent)
	{
		char c = '?';
		if (ent == DynLib::ENTITY::NONE)
			c = ' ';
		else if (ent == DynLib::ENTITY::PLAYER)
			c = 'O';
		else if (ent == DynLib::ENTITY::WALL)
			c = '#';
		else if (ent == DynLib::ENTITY::ITEM)
			c = '*';
		mvprintw(y, x, &c);
		refresh();
	}

	void    LibGFX::dispText(int x, int y, std::string str)
	{
		(void)x;
		(void)y;
		(void)str;
		mvprintw(y, x, "%s", str.c_str());
		//printf("abcdef");
		//refresh();
	}
}
