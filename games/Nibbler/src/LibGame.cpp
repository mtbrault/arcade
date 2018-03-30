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
		:_map(20), _lib(nullptr), _score(0), _snek(4), _stat(1)
	{
		std::cout << "Game \"Momo'sSnekAdventure\" loaded." << std::endl;
		init();
	}
	
	void	LibGame::init()
	{
		_dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
		_stat = 1;
		for (auto it = _map.begin() ; it != _map.end() ; ++it) {
				it->reserve(20);
				(*it)[0] = DynLib::ENTITY::WALL;
				(*it)[19] = DynLib::ENTITY::WALL;
			   	std::fill(it->begin(), it->end(), DynLib::ENTITY::NONE);
		}
		_snek.reserve(4);
		_snek[0] = std::make_pair(9, 10);
		_snek[1] = std::make_pair(10, 10);
		_snek[2] = std::make_pair(11, 10);
		_snek[3] = std::make_pair(12, 10);
		moveSnek();
		showSnek();
		_bonus = {rand() % 20, rand() % 20};
		if (_bonus.first == 10)
			_bonus.first += 1;
	}

	void	LibGame::checkDir()
	{
		int k = _lib->getLastKey();

		if ((char)k == 'd')
			std::rotate(_dir.begin(), _dir.begin() + 1, _dir.end());
		else if ((char)k == 'q')
			std::rotate(_dir.rbegin(), _dir.rbegin() + 1, _dir.rend());
	}

	void	LibGame::moveSnek()
	{
		pos	next = std::make_pair(_snek[0].first + _dir[0].first, _snek[0].second + _dir[0].second);
		if (next.first <= 0 || next.first >= 20 || next.second <= 0 || next.second >= 20 ||
			_map[next.second][next.first] == PLAYER) {
			_stat = 0;
			return ;
		} else if (_map[next.second][next.first] != DynLib::ENTITY::ITEM) {
			_map[_snek.end()->second][_snek.end()->first] = DynLib::ENTITY::NONE;
			_snek.pop_back();

		}
		_snek.push_back(next);
		std::rotate(_snek.rbegin(), _snek.rbegin() + 1, _snek.rend());
	}

	void	LibGame::showSnek()
	{
		for (auto it = _snek.begin() ; it != _snek.end() ; ++it)
			_map[it->second][it->first] = DynLib::ENTITY::PLAYER;
	}
	
	void    LibGame::aff()
	{
		checkDir();
		moveSnek();
		for (int x = 0 ; x < 20 ; x += 1) {
			for (int y = 0 ; y < 20 ; x += 1) {
				_lib->display(x, y, _map[y][x]);
			}
		}
	}

	void	LibGame::setLibGfx(DynLib::IGfx &lib)
	{
		_lib = &lib;
	}
	
	int	LibGame::getLine()
	{
		return (0);
	}

	int	LibGame::getColumn()
	{
		return (0);
	}

	bool	LibGame::checkEnd()
	{
		return (!_stat);
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
