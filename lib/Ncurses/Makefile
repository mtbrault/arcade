##
## EPITECH PROJECT, 2018
## aracade
## File description:
## Nibbler makefile
##

CXX		= g++

RM		= rm -f

NAME		= ../lib_arcade_ncurses.so

SRC		= src/LibGFX.cpp

CXXFLAGS	+= -I ./inc -I ../../inc
CXXFLAGS	+= -W -Wall -Wextra -Werror -fpic

OBJS		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -shared -o $(NAME) $(OBJS) -fpic -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
