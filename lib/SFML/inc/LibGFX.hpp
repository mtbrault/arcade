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
#include "DynLib.hpp"

namespace DynLib {
	
        class   LibGFX : public IGfx {
	public:
		LibGFX();
		virtual ~LibGFX();

		virtual void	init(int, int);
		virtual void	destroy();
		virtual void	display(int x, int y, ENTITY entity);
		virtual void	refresh();
		virtual void	clear();
		virtual int	getKey();
		virtual int	getLastKey();
		virtual ENTITY	getOnWin(int x, int y);
		virtual void	dispText(int x, int y, std::string);

	private:
		int					_lk;
		sf::RenderWindow			*_window;
		std::map<int, sf::Keyboard::Key>	_keys;
       };
}
#endif
