/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** my_map_len
*/

#include "generator_header.h"

int my_map_len(char **map)
{
    if (*map == NULL)
        return -1;
    int i = 0;
    for (; map[i] != NULL; i += 1);
    return i;
}
