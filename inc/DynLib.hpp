//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Game interface
//

#ifndef DYNLIB_HPP_
# define DYNLIB_HPP_

#include <string>

namespace   DynLib {

	enum    ENTITY {                
		PLAYER,
		ENNEMY,
		OBSTACLE,
		ITEM
	};

	class   Game {
	public:
		virtual ~Game() = default;

		virtual void            aff() = 0;
		virtual bool            checkEnd() = 0;
//		virtual std::string     getSprite() = 0;
//		virtual char            getChar() = 0;
//		virtual int             getColor() = 0;
	};

	class   Gfx {
	public:
		virtual ~Gfx() = default;

		virtual void    init() = 0;
//		virtual void    destroy() = 0;
//		virtual void    display(std::pair<std::size_t, std::size_t>, 
//					DynLib::ENTITY, DynLib::Game &) = 0;
//		virtual void    dispText(std::pair<std::size_t, std::size_t>, std::string) = 0;
		virtual bool    checkKey(int) = 0;
	};

}

#endif
