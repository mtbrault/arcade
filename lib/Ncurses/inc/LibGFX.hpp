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
	class   LibGFX : public Gfx {
	public:
		LibGFX();
		virtual ~LibGFX() {};

		void	init();
		void    destroy();
		bool	checkKey(int);
		void    display(std::pair<std::size_t, std::size_t>, 
					DynLib::ENTITY, DynLib::Game &);
		void    dispText(std::pair<std::size_t, std::size_t>, std::string);
       };
}
#endif
