##
## EPITECH PROJECT, 2018
## Preoject name
## File description:
## makefile
##

all:
	make -C./solver/
	make -C./generator/

clean:
	make clean -C./solver/
	make clean -C./generator/

fclean:	clean
	make fclean -C./solver/
	make fclean -C./generator/

re:	fclean all

.PHONY : all clean fclean re