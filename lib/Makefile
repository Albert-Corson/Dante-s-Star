##
## EPITECH PROJECT, 2018
## My Makefile
## File description:
## makefile
##

SRC	=	get_char_pos.c		\
		my_copycat.c		\
		my_getnbr.c			\
		my_memcmp.c			\
		my_nisnum.c			\
		my_putchar.c		\
		my_putchar_err.c	\
		my_put_err_nbr.c	\
		my_puterror.c		\
		my_putstr.c			\
		my_strcpy.c			\
		my_strdup.c			\
		my_strlen.c			\
		my_tabledup.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ../include
CFLAGS	+=	-Wall -Wextra -Werror -g

NAME	=	libmy.a

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re