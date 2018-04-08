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
		:_lk(-1)
	{
		std::cout << "Graphic lib \"Ncurses\" loaded." << std::endl;
	}
	
	LibGFX::~LibGFX()
	{
	}

	void            nonCanon(const char reset)
	{
		static struct termios _oldt;
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
            curs_set(0) == ERR)
                throw std::exception();                                                          
        nonCanon(0);
	}

	void	LibGFX::clear()
	{
		erase();
	}
	
	void	LibGFX::refresh()
	{
		//refresh();
	}

	void	LibGFX::destroy()
	{
		nonCanon(1);
		endwin();	
        curs_set(1);
        echo();
        keypad(stdscr, false);
	}
	
	int	LibGFX::getKey()
	{
		int tmp = getch();
		_lk = tmp;
		while (tmp != -1) {
			_lk = tmp;
			tmp = getch();
		}
		return (_lk);
	}

	ENTITY LibGFX::getOnWin(int x, int y)
	{
		(void)x;
		(void)y;
		return (DynLib::ENTITY::PLAYER);
	}

	int	LibGFX::getLastKey()
	{
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
		else if (ent == DynLib::ENTITY::ENEMY)
			c = 'X';
		mvprintw(y, x, &c);
		refresh();
	}

	void    LibGFX::dispText(int x, int y, std::string str)
	{
		(void)x;
		(void)y;
		(void)str;
		mvprintw(y, x, "%s", str.c_str());
	}
}
