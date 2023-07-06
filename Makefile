##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## compil all binaries
##

all: 	make_lib compil_all_binaries

compil_all_binaries:
	make -C generator/
	make -C solver/

make_lib:
	make -C lib/my

clean:
	make -C generator/ clean
	make -C solver/ clean
	make -C lib/my clean

fclean:
	make -C generator/ fclean
	make -C solver/ fclean
	make -C lib/my fclean

re:	fclean all

.PHONY: all clean fclean re make_lib compil_all_binaries
