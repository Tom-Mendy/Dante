/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** my_project
*/

#include "generator_header.h"

int generator(int const x, int const y, int const perfect)
{
    srand(time(NULL));
    char **map = NULL;
    if (create_map(&map, y, x, 'X') == KO)
        return KO;
    if (generate_labyrinth(map, x, y) == KO) {
        free_map(map);
        return KO;
    }
    add_complexity_to_maze(map, x, y);
    if (perfect == 0)
        creat_imperfect(map, x, y);
    if (display_map(map) == KO){
        free_map(map);
        return KO;
    }
    free_map(map);
    return OK;
}
