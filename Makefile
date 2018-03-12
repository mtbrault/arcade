##
## EPITECH PROJECT, 2018
## Nanotekspice
## File description:
## Makefile
##

NAME	=	arcade

CC	=	g++

RM	=	rm -f

SRCS	=	./src/Main.cpp		\
		./src/HardCade.cpp	\
		./src/Loader.cpp	\
		./src/HardError.cpp

CPPFLAGS =	-I ./inc
CPPFLAGS +=	-W -Wall -Wextra -Werror -std=c++14

OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS =	-I ./inc
CPPFLAGS +=	-W -Wall -Wextra -ldl

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
