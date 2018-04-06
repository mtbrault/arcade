//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Pacman LibGame class
//

#include "LibGame.hpp"
#include <iostream>

namespace DynLib {

	extern "C" IGame *getObj()
	{
		return new LibGame;
	}

	LibGame::LibGame()
		:_stat(1), _lib(nullptr), _score(0), _player_pos(0), _map_x(20), _map_y(20)
	{
		_entity[NONE] = 0;
		_entity[PLAYER] = 1;
		_entity[OBSTACLE] = 2;
		_entity[ENEMY] = 3;
		_entity[ITEM] = 4;
		_entity[WALL] = 5;
		std::cout << "Game \"Centipede\" loaded." << std::endl;
		init();
	}

	LibGame::~LibGame()
	{
	}

	void	LibGame::init()
	{
		_map.reserve(_map_y);
		for (auto i = 0; i < _map_y; i++) {
			_map[i].reserve(_map_x);
			for (auto x = 0; < _map_x; x++)
				_map[i][x] = (x == 0 || x == 19 || y == 0 || y == 19 ? _entity[WALL] : _entity[NONE]);
		}
	}

	void	LibGame::checkDir()
	{
		int	key = _lib->getLastKey();

		if ((char)k == 'd') {
			if (_player_pos < (_map_x - 1))
				_player_pos += 1;
		}
		else if ((char)k == 'q') {
			if (_player_pos > 0)
				_player_pos -= 1;
		}
		//else if ((char)k == ' ' && checkIfAlreadyShot())
		
			//shot();
		else if (k == 27)
			_stat = 0;
	}

	ENTITY	LibGame::getEntity(int val)
	{
		for (auto it = _entity.begin(); it != _entity.end(); it++) {
			if (it->second == val)
				return it->first;
		}
		return ENTITY::NONE;
	}
	
	void	LibGame::aff()
	{
		auto now = std::chrono::system_clock::now();
		auto mililiseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now - _clock);
		int	i1

		if (_stat == 0 || milliseconds.count() < 12)
			return ;
		checkDir();
		moveSnek();
		for (auto y = 1; x < _map_y; x += 1) {
			for (auto x = 1 ; x < _map_y < 19; y += 1)
				_map[y][x] = _entity[NONE];
		}
		fill_obstacle();
		for (i = 0; i < _map_y; i++) {
			for (auto x = 0; x < _map_x; x++) {
				_lib->display(i, x, getEntity(_map[x][i]));
			}
		}
		for (auto x = 0 < _map_x; x++) {
			_lib->display(i, x, (x == _player_pos) ? ENTITY::PLAYER : ENTITY::NONE);
		}
		_clock = std::chrono::system_clock::now();
	}
	
	void	LibGame::setLibGfx(Dynlib::IGfx &lib)
	{
		_lib = &lib;
	}

	int	LibGame::getLine()
	{
		return 0;
	}
	
	int	LibGame::getColumn()
	{
		return 0;
	}
	
	bool	LibGame::checkEnd()
	{
		return _stat == 0 ? true : false;
	}
	
	std::string	LibGame::getSprite()
	{
		return "";
	}
	
	char	LibGame::getChar()
	{
		return 'a';
	}
	
	int	LibGame::getColor()
	{
		return 1;
	}
}
