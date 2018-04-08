//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFML LibGFX header
//

#ifndef LibGFX_HPP_
# define LibGFX_HPP_

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "DynLib.hpp"

# define SIZE	60

namespace DynLib {
	
        class   LibGFX : public IGfx {
	public:
		LibGFX();
		~LibGFX();

		void	init(int, int);
		void	destroy();
		void	display(int x, int y, ENTITY entity);
		void	refresh();
		void	clear();
		int	getKey();
		int	getLastKey();
		ENTITY	getOnWin(int x, int y);
		void	dispText(int x, int y, std::string);

	private:
		int					_lk;
		sf::RenderWindow			_window;
		std::map<int, sf::Keyboard::Key>	_keys;
		std::map<ENTITY, sf::Sprite>		_sprite;
       };
}
#endif
