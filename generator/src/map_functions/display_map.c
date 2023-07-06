/*
** EPITECH PROJECT, 2023
** create map
** File description:
** create_map
*/

#include "generator_header.h"

int display_return(char **map, int const i)
{
    if (map[i + 1] != NULL){
        if (write(1, "\n", 1) == -1)
            return KO;
    }
    return OK;
}

int display_map(char **map)
{
    if (map == NULL)
        return KO;
    for (int i = 0; map[i] != NULL; i += 1) {
        if (write(1, map[i], strlen(map[i])) == -1)
            return KO;
        if (display_return(map, i) == KO)
            return KO;
    }
    return OK;
}
