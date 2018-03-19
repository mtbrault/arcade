//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFML LibGFX class
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
	std::cout << "je suis sfml" << std::endl;
}
