//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ncurses LibGFX header
//

#ifndef LibGFX_HPP_
# define LibGFX_HPP_

#include <ncurses.h>
#include "DynLib.hpp"

namespace DynLib {
	class   LibGFX : public IGfx {
	public:
		LibGFX();
		virtual ~LibGFX() {};

		void init(int, int);
		virtual void destroy();
		virtual void display(int x, int y, ENTITY entity);
		virtual void refresh();
		virtual void clear();
		virtual int getKey();
		virtual int getLastKey();
		virtual ENTITY getOnWin(int x, int y);
		// virtual void    display(std::pair<std::size_t, std::size_t>,                                  
		//                         ENTITY, DynLib::IGame &) = 0;                                         
		virtual void dispText(int x, int y, std::string);

       };
}
#endif
