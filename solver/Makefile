##
## EPITECH PROJECT, 2018
## My Makefile
## File description:
## makefile
##

SRC	=	main.c			\
		get_maze.c		\
		my_copycat.c	\
		table_tools.c	\
		maze_solver.c	\
		stack_tool.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -O2
CFLAGS	+= -I ../include

DEBUG ?= 0
ifneq ($(DEBUG), 0)
	ifeq ($(DEBUG), 1)
		CFLAGS += -g -g3 -ggdb
	endif
endif

NAME	=	solver

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

debug: fclean
	make DEBUG=1 -C./

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean re fclean