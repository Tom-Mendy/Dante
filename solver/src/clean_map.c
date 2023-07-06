/*
** EPITECH PROJECT, 2023
** clean_map
** File description:
** clean_map
*/

#include <unistd.h>

static void switch_char(char **map, int x, int y)
{
    if (map[y][x] != 'X')
        map[y][x] = '*';
}

void clean_map(char **map)
{
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            switch_char(map, x, y);
        }
    }
}
