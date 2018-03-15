##
## EPITECH PROJECT, 2018
## Arcade
## File description:
## Core program Makefile
##

CXX	=	g++

RM	=	rm -f

NAME	=	arcade

SRCS	=	./src/Main.cpp		\
		./src/HardCade.cpp	\
		./src/Loader.cpp	\
		./src/HardError.cpp

CXXFLAGS =	-I ./inc
CXXFLAGS +=	-W -Wall -Wextra -Werror -std=c++14

OBJS	=	$(SRCS:.cpp=.o)

all: core games graphicals

core: $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)  $(CXXFLAGS)

games:  make -C ./games/Pacman
	make -C ./games/Nibbler

graphicals:	make -C ./lib/Ncurses
		make -C ./lib/OpenGL
		make -C ./lib/SFML

clean:
	$(RM) $(OBJS)
	make clean -C ./games/Pacman
	make clean -C ./games/Nibbler
	make clean -C ./libs/Ncurses
	make clean -C ./libs/OpenGL
	make clean -C ./libs/SFML

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./games/Pacman
	make fclean -C ./games/Nibbler
	make fclean -C ./libs/Ncurses
	make fclean -C ./libs/OpenGL
	make fclean -C ./libs/SFML

re: fclean all

.PHONY: all clean fclean re
