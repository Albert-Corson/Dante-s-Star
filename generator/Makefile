##
## EPITECH PROJECT, 2018
## My Makefile
## File description:
## makefile
##

SRC	=	main.c				\
		maze_format.c		\
		maze_init.c			\
		maze_display.c		\
		maze_free.c			\
		stack_tool.c		\
		random_nbr.c		\
		depth_first_tools.c	\
		depth_first.c		\
		imperfect.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g
CFLAGS	+= -I ../include

NAME	=	generator

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C../lib/
	gcc -o $(NAME) $(OBJ) -L../lib/ -lmy

clean:
	make clean -C../lib/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C../lib/
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean re fclean