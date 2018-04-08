//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Nibbler LibGame class
//

#include "LibGame.hpp"
#include <iostream>
#include <vector>

namespace DynLib {

	extern "C" IGame *getObj()
	{
		return new LibGame;
	}

	LibGame::LibGame()
		:_map(20), _lib(nullptr), _score(0), _snek(4), 
		_stat(1), _init(0), _clock(std::chrono::system_clock::now())
	{
		std::cout << "Game \"Momo'sSnekAdventure\" loaded." << std::endl;
		init();
	}

	LibGame::~LibGame()
	{
	}
	
	void	LibGame::placeBonus()
	{
		_bonus = std::make_pair((rand() % 18) + 1, (rand() % 18) + 1);
		while (_map[_bonus.second][_bonus.first] == '1') {
			_bonus.first = (rand() % 18) + 1;
			_bonus.second = (rand() % 18) + 1;
		}
		_map[_bonus.second][_bonus.first] = '3';
	}

	void	LibGame::init()
	{
		if (_init == 1) {
			_stat = 1;
			return ;
		}
		_init = 1;
		_dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
		_stat = 1;
		_map.reserve(20);
		for (auto y = 0 ; y < 20 ; y += 1) {
			_map[y].reserve(20);
			for (auto x = 0 ; x < 20 ; x += 1)
				_map[y][x] = (x == 0 || x == 19 || y == 0 || y == 19 ? '2' : '0');
		}
		std::fill(_map.begin()->begin(), _map.begin()->end(), '2');
		std::fill(_map.begin()->begin(), _map.begin()->end(), '2');
		_snek = {
			std::make_pair(9, 10),
			std::make_pair(10, 10),
			std::make_pair(11, 10),
			std::make_pair(12, 10)
		};
		showSnek();
		placeBonus();
	}

	void	LibGame::checkDir()
	{
		int k = _lib->getLastKey();
		if ((char)k == 'd')
			std::rotate(_dir.begin(), _dir.begin() + 1, _dir.end());
		else if ((char)k == 'q')
			std::rotate(_dir.rbegin(), _dir.rbegin() + 1, _dir.rend());
		else if (k == 27) {
			_stat = 0;
			return ;
		}
		//moveSnek();
	}

	void	LibGame::moveSnek()
	{
		pos	next = std::make_pair(_snek.begin()->first + _dir.begin()->first,
								_snek.begin()->second + _dir.begin()->second);
		(void)next;
		if (next.first <= 0 || next.first >= 19 || next.second <= 0 || next.second >= 19 ||
			_map[next.second][next.first] == '1') {
			_stat = 0;
			_init = 0;
			return ;
		} else if (_map[next.second][next.first] != '3') {
			_snek.erase(_snek.end());
		} else if (next.first == _bonus.first || next.second == _bonus.second)
			placeBonus();
		_snek.insert(_snek.begin(), next);
	}

	void	LibGame::showSnek()
	{
		for (auto it = _snek.begin() ; it != _snek.end() ; ++it)
			_map[it->second][it->first] = '1';
	}
	
	void    LibGame::aff()
	{
		auto now = std::chrono::system_clock::now();
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now - _clock);
		if (milliseconds.count() < 20 || !_stat)
			return ;
		//if (milliseconds.count() < 5000000) {
			checkDir();
			moveSnek();
		//}
		for (auto x = 1 ; x < 19 ; x += 1) {
			for (auto y = 1 ; y < 19 ; y += 1)
					_map[y][x] = '0';
		}
		showSnek();
		_map[_bonus.second][_bonus.first] = '3';
		for (auto x = 0 ; x < 20 ; x += 1) {
			for (auto y = 0 ; y < 20 ; y += 1) {
				if (_map[y][x] == '0')
					_lib->display(x, y, DynLib::ENTITY::NONE);
				else if (_map[y][x] == '1')
					_lib->display(x, y, DynLib::ENTITY::PLAYER);
				else if (_map[y][x] == '2')
					_lib->display(x, y, DynLib::ENTITY::WALL);
				else if (_map[y][x] == '3')
					_lib->display(x, y, DynLib::ENTITY::ITEM);
			}
		}
		_clock = std::chrono::system_clock::now();
	}

	void	LibGame::setLibGfx(DynLib::IGfx &lib)
	{
		_lib = &lib;
	}
	
	int	LibGame::getLine()
	{
		return (20);
	}

	int	LibGame::getColumn()
	{
		return (20);
	}

	bool	LibGame::checkEnd()
	{
		return (_stat == 0 ? 1 : 0);
	}
	
	std::string	LibGame::getSprite()
	{
		return ("t");
	}

	char	LibGame::getChar()
	{
		return ('c');
	}

	int	LibGame::getColor()
	{
		return (1);
	}
}
