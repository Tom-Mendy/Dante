/*
** EPITECH PROJECT, 2023
** check_neighbor
** File description:
** check_neighbor
*/

#include <unistd.h>
#include "solver_header.h"
#include "maze.h"
#include "my.h"
#include "vector.h"

maze_t *neighbor_top(char **map, maze_t *neighbor_list, maze_t *case_check)
{
    int x = case_check->x;
    int y = case_check->y;
    map[y - 1][x] = 'N';
    neighbor_list = add_maze_case_in_list(neighbor_list,
    (vector_t){.x = x, .y = y - 1}, calcul_distance(x, y - 1, 0, 0) +
    calcul_distance(x, y - 1, my_strlen(map[0]) - 1, my_tablen(map)),
    case_check);
    return neighbor_list;
}

maze_t *neighbor_bot(char **map, maze_t *neighbor_list, maze_t *case_check)
{
    int x = case_check->x;
    int y = case_check->y;
    map[y + 1][x] = 'N';
    neighbor_list = add_maze_case_in_list(neighbor_list,
    (vector_t){.x = x, .y = y + 1}, calcul_distance(x, y + 1, 0, 0) +
    calcul_distance(x, y + 1, my_strlen(map[0]) - 1, my_tablen(map)),
    case_check);
    return neighbor_list;
}

maze_t *neighbor_right(char **map, maze_t *neighbor_list, maze_t *case_check)
{
    int x = case_check->x;
    int y = case_check->y;
    map[y][x + 1] = 'N';
    neighbor_list = add_maze_case_in_list(neighbor_list,
    (vector_t){.x = x + 1, .y = y}, calcul_distance(x + 1, y, 0, 0) +
    calcul_distance(x + 1, y, my_strlen(map[0]) - 1, my_tablen(map)),
    case_check);
    return neighbor_list;
}

maze_t *neighbor_left(char **map, maze_t *neighbor_list, maze_t *case_check)
{
    int x = case_check->x;
    int y = case_check->y;
    map[y][x - 1] = 'N';
    neighbor_list = add_maze_case_in_list(neighbor_list,
    (vector_t){.x = x - 1, .y = y}, calcul_distance(x - 1, y, 0, 0) +
    calcul_distance(x - 1, y, my_strlen(map[0]) - 1, my_tablen(map)),
    case_check);
    return neighbor_list;
}

maze_t *check_neighbor(char **map, maze_t *neighbor_list, maze_t *case_check)
{
    int x = case_check->x;
    int y = case_check->y;
    if (map[y][x + 1] != '\0' && map[y][x + 1] == '*') {
        neighbor_list = neighbor_right(map, neighbor_list, case_check);
    }
    if (x != 0 && map[y][x - 1] == '*') {
        neighbor_list = neighbor_left(map, neighbor_list, case_check);
    }
    if (map[y + 1] != NULL && map[y + 1][x] == '*') {
        neighbor_list = neighbor_bot(map, neighbor_list, case_check);
    }
    if (y != 0 && map[y - 1][x] == '*') {
        neighbor_list = neighbor_top(map, neighbor_list, case_check);
    }
    return neighbor_list;
}
