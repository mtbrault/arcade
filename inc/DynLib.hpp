//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Gfx & Gamex interface
//

#include <string>

#ifndef DYNLIB_HPP
# define DYNLIB_HPP

namespace   DynLib {

    enum ENTITY {
        PLAYER,
        ENEMY,
        OBSTACLE,
        ITEM,
    	WALL,
        NONE
    };

    class   IGfx {
    public:
        virtual ~IGfx() = default;

        virtual void init(int, int) = 0;
        virtual void destroy() = 0;
        virtual void display(int x, int y, ENTITY entity) = 0;
        virtual void refresh() = 0;
        virtual void clear() = 0;
        virtual int getKey() = 0;
        virtual int getLastKey() = 0;
        virtual ENTITY getOnWin(int x, int y) = 0;
        virtual void dispText(int x, int y, std::string) = 0;
};

    class   IGame {
    public:
        virtual ~IGame() = default;
        virtual void setLibGfx(DynLib::IGfx &) = 0;
        virtual void init() = 0;
        virtual void aff() = 0;
        virtual int getLine() = 0;
        virtual int getColumn() = 0;
        virtual bool            checkEnd() = 0;
        virtual std::string     getSprite() = 0;
        virtual char            getChar() = 0;
        virtual int             getColor() = 0;
    };
}

#endif /* !DYNLIB_HPP */
