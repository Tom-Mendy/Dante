##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## compil antman binary
##

SRC		=	list/add_elem.c		\
			list/create_elem.c	\
			list/free_list.c	\
			list/min_list.c		\
			list/my_listlen.c	\
			list/delink_list.c	\
			list/print_list.c	\
			error/file.c		\
			error/map.c			\
			check_neighbor.c	\
			clean_map.c			\
			free_tab.c			\
			astar_solution.c	\
			my_tablen.c			\
			distance.c			\
			main.c

DIR_SRC 	= 	$(addprefix src/, $(SRC))

OBJ			=	$(DIR_SRC:.c=.o)

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./include/ -I../lib/include/ -lm -ggdb3

NAME		=	solver

MY_LIB		=	-L ../lib/my -lmy

all: 	make_lib $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(MY_LIB) $(CPPFLAGS)

make_lib:
	make -C ../lib/my

clean:
	make -C ../lib/my clean
	rm -f $(OBJ) vgcore* *.gc*

fclean:	clean
	make -C ../lib/my fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re make_lib
