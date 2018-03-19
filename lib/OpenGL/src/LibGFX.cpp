//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// OpenGL LibGFX class
//

#include "LibGFX.hpp"
#include <iostream>

extern "C" LibGFX *create_obj()
{
	return new LibGFX;
}

LibGFX::LibGFX()
{
}

void    LibGFX::init()
{
	std::cout << "je suis opengl" << std::endl;
}
