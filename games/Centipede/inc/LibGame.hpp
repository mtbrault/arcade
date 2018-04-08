//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Pacman LibGame header
//

#ifndef LibGame_HPP_
# define LibGame_HPP_

#include <map>
#include <chrono>
#include <vector>
#include <ctime>
#include "DynLib.hpp"

namespace DynLib {

	typedef std::pair<int, int> posxy;

	struct		Centipede
	{
		int			dir;
		std::vector<posxy>	body;
	};

	class   LibGame : public IGame {
	public:
		LibGame();
		~LibGame();

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
		void		checkDir();
		void		loadObstacles();
		void		shoot();
		void		centipeder();
		void		moveShot();
		void		movePlayer(posxy);

		const int sizex = 20;
		const int sizey = 20;

		DynLib::IGfx				*_lib;
		posxy					_pos;
		posxy					_shot;
		std::map<posxy, int>			_obs;
		std::vector<Centipede>			_cents;
		int					_score;
		int					_stat;
		bool					_init;
		std::map<int, posxy>			_dirs;
		std::chrono::system_clock::time_point	_clock;
	};
}
#endif
