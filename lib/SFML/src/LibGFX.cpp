//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFML LibGFX class
//

#include <iostream>
#include "LibGFX.hpp"

namespace DynLib {

	
	
	extern "C" IGfx *getObj()
	{
		return new LibGFX;
	}

	LibGFX::LibGFX()
		:_lk(0)
	{
		_keys[0] = sf::Keyboard::A;
		_keys[1] = sf::Keyboard::B;
		_keys[2] = sf::Keyboard::C;
		_keys[3] = sf::Keyboard::D;
		_keys[4] = sf::Keyboard::E;
		_keys[5] = sf::Keyboard::F;
		_keys[6] = sf::Keyboard::G;
		_keys[7] = sf::Keyboard::H;
		_keys[8] = sf::Keyboard::I;
		_keys[9] = sf::Keyboard::J;
		_keys[10] = sf::Keyboard::K;
		_keys[11] = sf::Keyboard::L;
		_keys[12] = sf::Keyboard::M;
		_keys[13] = sf::Keyboard::N;
		_keys[14] = sf::Keyboard::O;
		_keys[15] = sf::Keyboard::P;
		_keys[16] = sf::Keyboard::Q;
		_keys[17] = sf::Keyboard::R;
		_keys[18] = sf::Keyboard::S;
		_keys[19] = sf::Keyboard::T;
		_keys[20] = sf::Keyboard::U;
		_keys[21] = sf::Keyboard::V;
		_keys[22] = sf::Keyboard::W;
		_keys[23] = sf::Keyboard::X;
		_keys[24] = sf::Keyboard::Y;
		_keys[25] = sf::Keyboard::Z;
		_keys[26] = sf::Keyboard::Escape;
		_keys[27] = sf::Keyboard::Subtract;
		_keys[28] = sf::Keyboard::Return;
		std::cout << "Graphic lib \"SFML\" loaded." << std::endl;
	}

	LibGFX::~LibGFX()
	{
		delete _window;
	}
	
	void    LibGFX::init(int a, int b)
	{
		(void)a;
		(void)b;
		_window = new sf::RenderWindow(sf::VideoMode(1200, 1080), (std::string)"Arcade");
		_window->setFramerateLimit(60);
	}

	void	LibGFX::destroy()
	{
		_window->close();
	}

	void	LibGFX::display(int x, int y, ENTITY entity)
	{
		sf::Texture	texture;
		sf::Sprite	sprite;

		(void)entity;
		if (!texture.loadFromFile("../texture/hokot6a.png"))
			return ;
		texture.setSmooth(true);
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(10, 10, 10, 10));
		sprite.setPosition(sf::Vector2f(x, y));
		_window->draw(sprite);
		_window->display();
	}
	
	void	LibGFX::refresh()
	{
		//_window->display();
	}

	void	LibGFX::clear()
	{
		_window->clear();
	}

	int	LibGFX::getKey()
	{
		sf::Event	event;
		
		if (_window->pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				for (auto it = _keys.begin(); it != _keys.end(); it++) {
					if (event.key.code == it->second) {
						_lk = it->first;
						return it->first;
					}
				}
			}
			else if (event.type == sf::Event::Closed)
				destroy();
		}
		return -1;
	}
	
	int	LibGFX::getLastKey()
	{
		return _lk;
	}

	ENTITY	LibGFX::getOnWin(int x, int y)
	{
		(void)x;
		(void)y;
		return ENTITY::ENEMY;
	}
	
	void	LibGFX::dispText(int x, int y, std::string str)
	{
		sf::Font	font;
		sf::Text	text;

		if (!font.loadFromFile("../font/arial.ttf"))
			return ;
		text.setFont(font);
		text.setString(str);
		text.setCharacterSize(10);
		text.setStyle(sf::Text::Bold);
		text.setPosition(sf::Vector2f(x, y));
		_window->draw(text);
	}
}
