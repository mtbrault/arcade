//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// OpenGL LibGFX header
//

#ifndef LibGFX_HPP_
# define LibGFX_HPP_

# include "DynLib.hpp"

namespace DynLib {
	class   LibGFX : public Gfx {
	public:
		LibGFX();
		virtual ~LibGFX() {};

	        virtual void	init();
		virtual bool	checkKey(int);
	};
}
#endif
