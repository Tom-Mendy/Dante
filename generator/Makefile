##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## compil giantman binary
##

SRC		=	main.c												\
			generator.c											\
			error.c												\
			my_is_num.c											\
			my_str_is_num.c										\
			help.c												\
			generate_labyrinth.c								\
			creat_imperfect.c									\
			add_complexity_to_maze.c							\
			cell_functions/create_cells.c						\
			cell_functions/generate_directions_coordinates.c	\
			cell_functions/shuffle_cells_tab.c					\
			map_functions/create_map.c							\
			map_functions/count_char_in_map.c					\
			map_functions/display_map.c							\
			map_functions/my_map_len.c							\
			map_functions/free_map.c

DIR_SRC 	= 	$(addprefix src/, $(SRC))

OBJ			=	$(DIR_SRC:.c=.o)

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./include/ -I../lib/include/ -ggdb3

NAME		=	generator

MY_LIB		=	-L ../lib/my -lmy

all: 	make_lib $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(MY_LIB)

docker: make_lib $(OBJ)
	gcc -o $(NAME) -static $(OBJ) $(MY_LIB) $(CPPFLAGS)

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
