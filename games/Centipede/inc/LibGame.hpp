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

	typedef struct			obstacle_s
	{
		int			x;
		int			y;
		int			life;
		struct obstacle_s	*next;
	}				obstacle_t;
	
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
		void		fillObstacle();
		void		initObstacle();
		void		checkDir();
		int		checkObstacle(int, int);
		ENTITY		getEntity(int);
		void		shot();
		void		moveShot();
		void		touchObstacle(int ,int);
		int				_stat;
		DynLib::IGfx			*_lib;
		std::map<ENTITY, int>		_entity;
		int				_score;
		int				_player_pos;
		int				_map_x;
		int				_map_y;
		std::vector<std::vector<int>>	_map;
		std::vector<obstacle_t>		_obstacle;
		std::chrono::system_clock::time_point	_clock;
		int				_isShot;
		std::pair<int, int>		_shotCoord;
	};
}
#endif
