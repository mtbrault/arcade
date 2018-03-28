//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Pacman LibGame header
//

#ifndef LibGame_HPP_
# define LibGame_HPP_

# include "DynLib.hpp"

namespace DynLib {
	class   LibGame : public IGame {
	public:
		LibGame();
		virtual ~LibGame() ;

		virtual void    aff();
		virtual bool	checkEnd();
		virtual std::string     getSprite();
		virtual char            getChar();
		virtual int             getColor();
	};
}
#endif
