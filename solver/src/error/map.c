/*
** EPITECH PROJECT, 2023
** map
** File description:
** map
*/

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "solver_header.h"
#include "my.h"

int width_map(char *buffer)
{
    int width = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            width++;
    }
    return width + 1;
}

char **tab_fill_null(char **map, int size)
{
    for (int i = 0; i <= size; i++)
        map[i] = NULL;
    return map;
}

bool valid_line(char *line, int line_size, int old_line_size)
{
    if (old_line_size != line_size && old_line_size != 0)
        return false;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != 'X' && line[i] != '*')
            return false;
    }
    return true;
}

char **create_map(char *buffer)
{
    int old_line_size = 0;
    if (my_strlen(buffer) != 1 && buffer[my_strlen(buffer) - 1] == '\n')
        return NULL;
    char **map = my_str_to_word_array(buffer, '\n');
    if (map == NULL)
        return NULL;
    for (int i = 0; map[i] != NULL; i++) {
        if (!valid_line(map[i], my_strlen(map[i]), old_line_size)) {
            free_tab(map);
            return NULL;
        }
        old_line_size = my_strlen(map[i]);
    }
    if (map[0][0] != '*' ||
    map[my_tablen(map) - 1][my_strlen(map[0]) - 1] != '*') {
        free_tab(map);
        return NULL;
    }
    return map;
}
