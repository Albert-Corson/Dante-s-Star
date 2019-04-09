##
## EPITECH PROJECT, 2019
## my_solver
## File description:
## Makefile
##

SRC	=	main.c		\
		solver.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -ggdb

NAME	=	solver

$(NAME):	$(OBJ)
	gcc -o$(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

test run:
		./$(NAME)

.PHONY: all clean fclean re