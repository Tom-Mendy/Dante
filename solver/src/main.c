/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include "solver_header.h"

int main(int const ac, char *const *const av)
{
    char *buffer = NULL;
    char **map = NULL;
    if (ac != 2)
        return KO;
    if ((buffer = file_not_valid(av[1])) == NULL)
        return KO;
    if ((map = create_map(buffer)) == NULL) {
        free(buffer);
        return KO;
    }
    free(buffer);
    if (map == NULL)
        return KO;
    return maze_solution(map);
}
