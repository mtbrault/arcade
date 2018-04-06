//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Pacman LibGame header
//

#ifndef LibGame_HPP_
# define LibGame_HPP_

#include <map>
# include "DynLib.hpp"

namespace DynLib {
	class   LibGame : public IGame {
	public:
		LibGame();
		~LibGame() ;

		void		setLibGfx(DynLib::IGfx &);
		void		init();
		void		aff();
		int		getLine();
		int		getColumn();
		bool		checkEnd();
		std::string	getSprite();
		char		getChar();
		int		getColor();

	private:
		int		_stat;
		DynLib::IGfx	*_lib;
		int		_score;
		int		_player_pos;
		std::map<ENTITY, int>	_entity; 
	};
}
#endif
