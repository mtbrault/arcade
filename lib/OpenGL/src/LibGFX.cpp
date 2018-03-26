//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// OpenGL LibGFX class
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

	void displayMe(void)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(0.0, 0.5, 0.0);
		glEnd();
		glFlush();
	}

	void keyboard(unsigned char key, int x, int y)
	{
		(void) x;
		(void) y;
		if (key == 'q' || key == 'Q')
			exit(EXIT_SUCCESS);
	}
	
	void    LibGFX::init()
	{
		int	i = 0;

		std::cout << "Loading - OpenGL Library" << std::endl;
		glutInit(&i, NULL);
		glutInitDisplayMode(GLUT_SINGLE);
		glutInitWindowSize(300, 300);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("HardCade - OpenGL");
		glutDisplayFunc(displayMe);
		glutKeyboardFunc(keyboard);
		glutMainLoop();
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
