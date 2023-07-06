/*
** EPITECH PROJECT, 2023
** create map
** File description:
** create_map
*/

#include "generator_header.h"

int create_map(char ***map, int const height, int const width, char const c)
{
    (*map) = malloc(sizeof(char *) * (height + 1));
    if ((*map) == NULL)
        return KO;
    for (int i = 0; i < height; i += 1){
        (*map)[i] = malloc(sizeof(char) * (width + 1));
        if ((*map)[i] == NULL)
            return KO;
        for (int j = 0; j < width; j += 1){
            (*map)[i][j] = c;
        }
        (*map)[i][width] = '\0';
    }
    (*map)[height] = NULL;
    return OK;
}
