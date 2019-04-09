##
## EPITECH PROJECT, 2018
## My Makefile
## File description:
## makefile
##

SRC	=	main.c			\
		get_maze.c		\
		solve_maze.c	\
		my_copycat.c	\
		table_tools.c	\
		solver.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g
CFLAGS	+= -I ../include

NAME	=	solver

all:    $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean re fclean