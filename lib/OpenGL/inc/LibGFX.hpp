//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// OpenGL LibGFX header
//

#ifndef LibGFX_HPP_
# define LibGFX_HPP_

# include <GL/glut.h>
# include "DynLib.hpp"

namespace DynLib {
	class   LibGFX : public Gfx {
	public:
		LibGFX();
		virtual ~LibGFX() {};

		virtual void	init();
		virtual void    destroy();
		virtual bool	checkKey(int);
		virtual void    display(std::pair<std::size_t, std::size_t>, 
					DynLib::ENTITY, DynLib::Game &);
		virtual void    dispText(std::pair<std::size_t, std::size_t>, std::string);
	};
}
#endif
