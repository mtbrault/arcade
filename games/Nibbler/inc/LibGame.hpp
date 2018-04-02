//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Nibbler LibGame header
//

#ifndef LibGame_HPP_
# define LibGame_HPP_

#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
# include "DynLib.hpp"


typedef std::pair<int, int> pos;

namespace DynLib {
	class   LibGame : public IGame {
	public:
		LibGame();
		virtual ~LibGame() {};

		virtual void setLibGfx(DynLib::IGfx &);
		virtual void init();
	    virtual void aff();
		virtual int getLine();
		virtual int getColumn();
		virtual bool checkEnd();
		virtual std::string getSprite();
		virtual char getChar();
		virtual int getColor();

	private:
		void	checkDir();
		void	moveSnek();
		void	showSnek();
		void	placeBonus();
		
		std::vector<std::vector<int>>	_map;
		DynLib::IGfx					*_lib;
		int								_score;
		std::vector<pos>				_snek;
		std::vector<pos>				_dir;
		pos								_bonus;
		int 							_stat;
		bool							_init;
		std::chrono::system_clock::time_point _clock;
	};
}
#endif
