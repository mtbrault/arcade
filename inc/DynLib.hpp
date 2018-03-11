//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Game interface
//

#ifndef DYNLIB_HPP_
# define DYNLIB_HPP_

namespace   DynLib {

    enum    ENTITY {                
        PLAYER,
        ENNEMY,
        OBSTACLE,
        ITEM
    };

    class   Game {
    public:
        virtual ~Game() = 0;

        //virtual void            aff() = 0;
        virtual bool            checkEnd() = 0;
        virtual std::string     getSprite() = 0;
        virtual char            getChar() = 0;
        virtual int             getColor() = 0;

    private:
        
    };

    class   Gfx {
    public:
        virtual ~Gfx() = 0;

        virtual void    init();
        virtual void    destroy();
        virtual void    display(std::pair<std::size_t, std::size_t>, 
                                DynLib::ENTITY, DynLib::Game &) = 0;
        virtual void    dispText(std::pair<std::size_t, std::size_t>, std::string);
        virtual bool    checkKey(int);


    private:

    };

}

#endif