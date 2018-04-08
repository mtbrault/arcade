##
## EPITECH PROJECT, 2018
## Arcade
## File description:
## Core program Makefile
##

CXX	=	g++ -g3

RM	=	rm -f

NAME	=	arcade

SRCS	=	./src/Main.cpp		\
		./src/HardCade.cpp	\
		./src/Loader.cpp	\
		./src/HardError.cpp

CXXFLAGS =	-I ./inc
CXXFLAGS +=	-W -Wall -Wextra -Werror -ldl -lGLU -lGL -lm -std=c++14

OBJS	=	$(SRCS:.cpp=.o)

all: core games graphicals

core: $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)  $(CXXFLAGS)

games:
	make -C games/Centipede/
	make -C games/Nibbler/

graphicals:
	make -C ./lib/Ncurses
	make -C ./lib/SFML

clean:
	$(RM) $(OBJS)
	make clean -C ./games/Centipede
	make clean -C ./games/Nibbler
	make clean -C ./lib/Ncurses
	make clean -C ./lib/SFML

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./games/Centipede
	make fclean -C ./games/Nibbler
	make fclean -C ./lib/Ncurses
	make fclean -C ./lib/SFML

re: fclean all

.PHONY: core games graphicals all clean fclean re
