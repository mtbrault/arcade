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
		:_lib(nullptr), _pos(sizex / 2, sizey - 1), _shot(-1, -1), _obs(), _cents(), 
		_stat(1), _init(0), _dirs(), _clock(std::chrono::system_clock::now())
	{
		std::cout << "Game \"Centipede\" loaded." << std::endl;
		_dirs['z'] = std::make_pair(0, -1);
		_dirs['q'] = std::make_pair(-1, 0);
		_dirs['s'] = std::make_pair(0, 1);
		_dirs['d'] = std::make_pair(1, 0);
		init();
	}

	LibGame::~LibGame()
	{
	}

	void 	LibGame::loadObstacles() 
	{
		for (auto nb = 0 ; nb < sizex ; nb += 1) {
			posxy tmp = {rand() % sizex, rand() % sizey};
			if ((tmp.first != _pos.first || tmp.second != _pos.second) && _obs.find(tmp) == _obs.end())
				_obs[tmp] = 5;
		}
	}

	void	LibGame::init()
	{
		if (_init == 1) {
			_stat = 1;
			return ;
		}
		_init = 1;
		_stat = 1;
		_pos = {sizex / 2, sizey - 1};
		loadObstacles();
	}

	void	LibGame::movePlayer(posxy dir)
	{
		posxy tmp = {_pos.first + dir.first, _pos.second + dir.second};
		auto it = _obs.find(tmp);
		if (it != _obs.end())
			return ;
		_pos.first += dir.first;
		_pos.second += dir.second;
		if (_pos.first == 0)
			_pos.first = 1;
		else if (_pos.first == sizex - 1)
			_pos.first = sizex - 2;
		if (_pos.second == sizey - 1)
		  _pos.second = sizey - 2;
		else if (_pos.second < sizey - sizey / 5)
			_pos.second = sizey - sizey / 5;
	}

	void 	LibGame::shoot()
	{
		if (_shot.first != -1 && _shot.second != -1)
			return ;
		_shot = {_pos.first, _pos.second - 1};
	}

	void	LibGame::checkDir()
	{
		int	key = _lib->getLastKey();
		auto it = _dirs.find(key);

		if (it != _dirs.end())
			movePlayer(it->second);
		else if ((char)key == ' ')
			shoot();
		else if (key == 27)
			_stat = 0;
	}

	void	LibGame::moveShot()
	{
		posxy tmp = {_shot.first, _shot.second - 1};
		if (tmp.second == 0) {
			_shot = {-1, -1};
			return ;
		}
		auto it = _obs.begin();
		for (it = _obs.begin() ; it != _obs.end() && (it->first.first != tmp.first || it->first.second != tmp.second) ; ++it);
		if (it != _obs.end()) {
			if (!(--it->second))
				_obs.erase(it);
			_shot = {-1, -1};
			return ;
		}
		for (auto it = _cents.begin() ; it != _cents.end() ; ++it) {
			auto find = it->body.begin();
			for (find = it->body.begin() ; find != it->body.end() && (find->first != _shot.first || find->second != _shot.second) ; ++find);
			if (find != it->body.end()) {
				if (it->body.size() > 1) {
					std::vector<posxy> cut = std::vector<posxy>(find + 1, it->body.end());
					std::vector<posxy> tmp = std::vector<posxy>(it->body.begin(), find);
					_obs[*find] = 5;
					it->body = tmp;
					if (cut.size() > 0) {
						cut[0].second += 1;
						_cents.push_back((Centipede){it->dir * -1, cut});
					}
				} else
					_cents.erase(it);
				_shot = {-1, -1};
				return ;
			}
		}
		_shot = tmp;
	}

	void	LibGame::centipeder()
	{
		if (_cents.size() == 0) {
			Centipede tmp = {1, {{0, 1},{-1, 1},{-2, 1},{-3, 1},{-4, 1}}};
			_cents.push_back(tmp);
		}
		for (auto it = _cents.begin() ; it != _cents.end() ; ++it) {
			posxy tmp = (it->body)[0];
			tmp.first += it->dir;
			auto find = _obs.find(tmp);
			if (tmp.first == sizex - 1 || tmp.first == 0 || find != _obs.end()) {
				tmp.first -= it->dir;
				tmp.second += 1;
				it->dir *= -1;
			}
			if (tmp.second >= sizey - 1 || (tmp.first == _pos.first && tmp.second == _pos.second)) {
				_stat = 0;
				_init = 0;
			}
			it->body.insert(it->body.begin(), tmp);
			it->body.pop_back();
		}
	}

	void	LibGame::aff()
	{
		auto now = std::chrono::system_clock::now();
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now - _clock);
		checkDir();
		if (_stat == 0)
			return ;
		moveShot();
		if (milliseconds.count() >= 500) {
			centipeder();
			_clock = std::chrono::system_clock::now();
		}
		_lib->clear();
		_lib->display(_pos.first, _pos.second, DynLib::ENTITY::PLAYER);
		if (_shot.first != -1 && _shot.second != -1)
			_lib->display(_shot.first, _shot.second, DynLib::ENTITY::ITEM);
		for (auto it = _obs.begin() ; it != _obs.end() ; ++it)
			_lib->display(it->first.first, it->first.second, DynLib::ENTITY::WALL);
		for (auto it = _cents.begin() ; it != _cents.end() ; ++it) {
			for (auto it2 = it->body.begin() ; it2 != it->body.end() ; ++it2) {
				if (it2->first > 0 && it2->first < sizex - 1)
					_lib->display(it2->first, it2->second, DynLib::ENTITY::ENEMY);
			}
		}
		
	}
	
	void	LibGame::setLibGfx(DynLib::IGfx &lib)
	{
		_lib = &lib;
	}

	int	LibGame::getLine()
	{
		return sizey;
	}
	
	int	LibGame::getColumn()
	{
		return sizex;
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
