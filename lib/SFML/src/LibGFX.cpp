//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFML LibGFX class
//

#include <iostream>
#include <exception>
#include "LibGFX.hpp"

namespace DynLib {
	
	extern "C" IGfx *getObj()
	{
		return new LibGFX;
	}

	LibGFX::LibGFX()
		:_lk(0)
	{
		_keys['a'] = sf::Keyboard::A;
		_keys['b'] = sf::Keyboard::B;
		_keys['c'] = sf::Keyboard::C;
		_keys['d'] = sf::Keyboard::D;
		_keys['e'] = sf::Keyboard::E;
		_keys['f'] = sf::Keyboard::F;
		_keys['g'] = sf::Keyboard::G;
		_keys['h'] = sf::Keyboard::H;
		_keys['i'] = sf::Keyboard::I;
		_keys['j'] = sf::Keyboard::J;
		_keys['k'] = sf::Keyboard::K;
		_keys['l'] = sf::Keyboard::L;
		_keys['m'] = sf::Keyboard::M;
		_keys['n'] = sf::Keyboard::N;
		_keys['o'] = sf::Keyboard::O;
		_keys['p'] = sf::Keyboard::P;
		_keys['q'] = sf::Keyboard::Q;
		_keys['r'] = sf::Keyboard::R;
		_keys['s'] = sf::Keyboard::S;
		_keys['t'] = sf::Keyboard::T;
		_keys['u'] = sf::Keyboard::U;
		_keys['v'] = sf::Keyboard::V;
		_keys['w'] = sf::Keyboard::W;
		_keys['x'] = sf::Keyboard::X;
		_keys['y'] = sf::Keyboard::Y;
		_keys['z'] = sf::Keyboard::Z;
		_keys[27] = sf::Keyboard::Escape;
		_keys[263] = sf::Keyboard::BackSpace;
		_keys[13] = sf::Keyboard::Return;
		std::cout << "Graphic lib \"SFML\" loaded." << std::endl;
	}

	LibGFX::~LibGFX()
	{
	}

	void	init_sprite(sf::Sprite &sprite, sf::Color color, std::string path)
	{
		sf::Texture	texture;

		if (!texture.loadFromFile(path))
			throw std::exception();
		sprite.setColor(color);
		sprite.setTexture(texture);
		sprite.setScale(0.3f, 0.3f);
	}
	
	void    LibGFX::init(int a, int b)
	{
		(void)a;
		(void)b;
		_window.create(sf::VideoMode(1920, 1080), "Arcade");
	        init_sprite(_sprite[PLAYER], sf::Color::Red, "texture/hokot6a.png");
		init_sprite(_sprite[ENEMY], sf::Color::Cyan, "texture/hokot6a.png");
		init_sprite(_sprite[OBSTACLE], sf::Color::White, "texture/hokot6a.png");
		init_sprite(_sprite[ITEM], sf::Color::Green, "texture/hokot6a.png");
		init_sprite(_sprite[WALL], sf::Color::Blue, "texture/hokot6a.png");
		init_sprite(_sprite[NONE], sf::Color::Black, "texture/hokot6a.png");
	}

	void	LibGFX::destroy()
	{
		_window.close();
	}

	void	LibGFX::display(int x, int y, ENTITY entity)
	{
		_sprite[entity].setPosition(x * 40, y * 40);
		_window.draw(_sprite[entity]);
	}
	
	void	LibGFX::refresh()
	{
		_window.display();
	}

	void	LibGFX::clear()
	{
		_window.clear(sf::Color::Black);
	}

	int	LibGFX::getKey()
	{
		for (auto it = _keys.begin(); it != _keys.end(); it++) {
			if (sf::Keyboard::isKeyPressed(it->second)) {
				_lk = it->first;
				return it->first;
			}
		}
		_lk = -1;
		return -1;
	}
	
	int	LibGFX::getLastKey()
	{
		for (auto it = _keys.begin(); it != _keys.end(); it++) {
			if (sf::Keyboard::isKeyPressed(it->second)) {
				_lk = it->first;
				return it->first;
			}
		}
		_lk = -1;
		return _lk;
	}

	ENTITY	LibGFX::getOnWin(int x, int y)
	{
		(void)x;
		(void)y;
		return ENTITY::NONE;
	}
	
	void	LibGFX::dispText(int x, int y, std::string str)
	{
		sf::Font	font;
		sf::Text	text;

		if (!font.loadFromFile("font/arial.ttf"))
			return ;
		text.setFont(font);
		text.setString(str);
		text.setCharacterSize(25);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(x * SIZE, y * SIZE));
		_window.draw(text);
	}
}
