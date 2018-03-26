//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Nibbler LibGame header
//

#ifndef LibGame_HPP_
# define LibGame_HPP_

# include "DynLib.hpp"

namespace DynLib {
	class   LibGame : public Game {
	public:
		LibGame();
		virtual ~LibGame() {};

	        virtual void    aff();
		virtual bool	checkEnd();
	};
}
#endif
