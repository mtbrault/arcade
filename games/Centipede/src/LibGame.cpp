//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Pacman LibGame class
//

#include <iostream>
#include "LibGame.hpp"

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
		_map.reserve(_map_x);
		for (auto x = 0; x < _map_x; x++) {
			_map[x].reserve(_map_y);
			for (auto y = 0; y < _map_y; y++)
				_map[x][y] = (x == 0 || x == (_map_x - 1) || y == 0 ? _entity[WALL] : _entity[NONE]);
		}
		initObstacle();
	}

	void	LibGame::checkDir()
	{
		int	key = _lib->getLastKey();

		if ((char)key == 'd') {
			if (_player_pos < (_map_x - 1))
				_player_pos += 1;
		}
		else if ((char)key == 'q') {
			if (_player_pos > 0)
				_player_pos -= 1;
		}
		//else if ((char)k == ' ' && checkIfAlreadyShot())
		
			//shot();
		else if (key == 27)
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

	int	LibGame::checkObstacle(int x, int y)
	{
		if (x == -1 || y == -1)
			return 1;
		for (auto it = _obstacle.begin(); it != _obstacle.end(); it++) {
			if (it->x == x && it->y == y && it->life > 0)
				return 1;
		}
		return 0;
	}
	
	void	LibGame::initObstacle()
	{
		int		x = -1;
		int		y = -1;
		obstacle_t	obstacle;

		for (int i = 0; i < 10; i++) {
		        while (checkObstacle(x, y) == 1) {
				x = rand() % _map_x;
				y = rand() % _map_y;
			}
			obstacle.x = x;
			obstacle.y = y;
			obstacle.life = 5;
			_obstacle.push_back(obstacle);
		}
	}
	
	void	LibGame::fillObstacle()
	{
		for (auto it = _obstacle.begin(); it != _obstacle.end(); it++) {
			if (it->life > 0)
				_map[it->x][it->y] = _entity[OBSTACLE];
		}
	}
	
	void	LibGame::aff()
	{
		auto now = std::chrono::system_clock::now();
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now - _clock);

		if (_stat == 0 || milliseconds.count() < 12)
			return ;
		for (int y = 1; y < _map_y; y++) {
			for (int x = 1; x < (_map_x - 1); x++) {
				_map[x][y] = _entity[NONE];
			}
		}
		fillObstacle();
		//Y a t il un tir ou un snake ?
		for (int y = 0; y < _map_y; y++) {
			for (int x = 0; x < _map_x; x++) {
				_lib->display(x, y, getEntity(_map[x][y]));
			}
		}
		for (int x = 0; x < _map_x; x++) {
			_lib->display(x, _map_y, (x == _player_pos ? ENTITY::PLAYER : ENTITY::NONE));
		}
		_clock = std::chrono::system_clock::now();
	}
	
	void	LibGame::setLibGfx(DynLib::IGfx &lib)
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
