//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ncurses LibGFX header
//

#ifndef LibGFX_HPP_
# define LibGFX_HPP_

#include "DynLib.hpp"

namespace DynLib {

	class   LibGFX : public IGfx {
	public:
		LibGFX();
		~LibGFX();

		void init(int, int);
		void destroy();
		void display(int x, int y, ENTITY entity);
		void refresh();
		void clear();
		int getKey();
		int getLastKey();
		ENTITY getOnWin(int x, int y);
		void dispText(int x, int y, std::string);

	private:
		int  		_lk;

       };
}
#endif
