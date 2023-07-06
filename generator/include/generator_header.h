/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#ifndef GENERATOR_HEADER_H_
    #define GENERATOR_HEADER_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include <unistd.h>
    #include <time.h>
    typedef struct cells{
        int x;
        int y;
    }cells_t;
    #define OK 0
    #define KO 84
    int generator(int const x, int const y, int const perfect);
    int create_map(char ***map, int const height, int const width,\
    char const c);
    int display_map(char ** map);
    int free_map(char **map);
    int error(int const ac, char const * const * const av);
    int my_is_num(char const c);
    int my_str_is_num(char const *str);
    int help(void);
    int display_int_map(int ** map);
    int generate_labyrinth(char **maze, int const x, int const y);
    cells_t create_cells(int x, int y);
    int my_map_len(char **map);
    cells_t *generate_directions_coordinates(void);
    void shuffle_cells_tab(cells_t *directions_coordinates, int len_tab);
    int count_char_in_map(char **maze, char const c);
    int creat_imperfect(char **map, int const x, int const y);
    int add_complexity_to_maze(char **maze, int const x, int const y);
#endif /* !GENERATOR_HEADER_H_ */
