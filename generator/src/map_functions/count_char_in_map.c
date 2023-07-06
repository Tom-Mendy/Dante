/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** count_char_in_map
*/

#include "generator_header.h"

static void count_char_in_map_sub(char **maze, int const i, int *count_c,
char const c)
{
    for (int j = 0; maze[i][j] != '\0'; j += 1) {
        if (maze[i][j] == c)
            count_c += 1;
    }
}

int count_char_in_map(char **maze, char const c)
{
    int count_c = 0;
    for (int i = 0; maze[i] != NULL; i += 1) {
        count_char_in_map_sub(maze, i, &count_c, c);
    }
    return count_c;
}
