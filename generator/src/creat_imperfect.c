/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** creat_imperfect
*/

#include "generator_header.h"

static int creat_imperfect_left(char **map, int const i, int *is_on)
{
    int count_wall = 0;
    if (map[i][0] == 'X')
        return 0;
    if (map[i + 1][0] == 'X')
        count_wall += 1;
    if (map[i][1] == 'X')
        count_wall += 1;
    if (count_wall == 2) {
        map[i - 1][0] = 'X';
        map[i + 1][0] = 'X';
        map[i][1] = 'X';
        *is_on = 1;
    }
    return 0;
}

static int creat_imperfect_top(char **map, int const i, int *is_on)
{
    int count_wall = 0;
    if (map[0][i] == 'X')
        return 0;
    if (map[0][i - 1] == 'X')
        count_wall += 1;
    if (map[0][i + 1] == 'X')
        count_wall += 1;
    if (map[1][i] == 'X')
        count_wall += 1;
    if (count_wall == 2) {
        map[0][i - 1] = 'X';
        map[0][i + 1] = 'X';
        map[1][i] = 'X';
        *is_on = 1;
    }
    return 0;
}

int creat_imperfect(char **map, int const x, int const y)
{
    int is_on = 0;
    if (x < 3 && y < 3)
        return 0;
    for (int i = 1; map[i + 1] != NULL && is_on == 0; i += 1) {
        creat_imperfect_left(map, i, &is_on);
    }
    for (int i = 1; map[0][i] != '\0' && is_on == 0; i += 1) {
        creat_imperfect_top(map, i, &is_on);
    }
    if (map[0][x - 1] == '*' && is_on == 0) {
        map[0][x - 2] = 'X';
        map[1][x - 1] = 'X';
        is_on = 1;
    }
    if (map[y - 1][0] == '*' && is_on == 0) {
        map[y - 1][1] = 'X';
        map[y - 2][0] = 'X';
        is_on = 1;
    }
    return 0;
}
