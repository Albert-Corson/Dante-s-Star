##
## EPITECH PROJECT, 2018
## My Makefile
## File description:
## makefile
##

SRC	=	main.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g
CFLAGS	+= -I ../include

NAME	=	solver

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C../lib/
	gcc -o $(NAME) $(OBJ)

clean:
	make clean -C../lib/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C../lib/
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean re fclean