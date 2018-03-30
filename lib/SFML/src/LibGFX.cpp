//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFML LibGFX class
//

#include "LibGFX.hpp"
#include <iostream>

namespace DynLib {

	extern "C" Gfx *getObj()
	{
		return new LibGFX;
	}

	LibGFX::LibGFX()
	{
	}
	
	void    LibGFX::init()
	{
		std::cout << "Loading - SFML Library" << std::endl;
	}

	void	LibGFX::destroy()
	{
	}
	
	bool	LibGFX::checkKey(int a)
	{
		(void) a;
		return true;
	}

	void    display(std::pair<std::size_t, std::size_t>,
			DynLib::ENTITY, DynLib::Game &)
	{
	}

	void    dispText(std::pair<std::size_t, std::size_t>, std::string)
	{
	}
}