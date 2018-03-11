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
			./src/HardCade.cpp \
		./src/Loader.cpp	

CPPFLAGS =	-I ./inc
CPPFLAGS +=	-W -Wall -Wextra -Werror -std=c++14

OBJS	=	$(SRCS:.cpp=.o)

CPPFLAGS =	-I ./inc
CPPFLAGS +=	-W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
