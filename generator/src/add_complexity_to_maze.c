/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** add_complexity_to_maze
*/

#include "generator_header.h"

static int pop_wall_randomly(char **maze, int const x, int const y,
int const nb_wall_to_pop)
{
    int x_rand = rand() % x;
    int y_rand = rand() % y;

    if (nb_wall_to_pop == 0)
        return 0;
    if (maze[y_rand][x_rand] != 'X') {
        return pop_wall_randomly(maze, x, y, nb_wall_to_pop);
    }
    maze[y_rand][x_rand] = '*';
    return pop_wall_randomly(maze, x, y, nb_wall_to_pop - 1);
}

int add_complexity_to_maze(char **maze, int const x, int const y)
{
    int nb_wall_in_map = count_char_in_map(maze, 'X');
    if (nb_wall_in_map <= 10)
        return 0;
    int nb_wall_to_pop = nb_wall_in_map / 10;
    return pop_wall_randomly(maze, x, y, nb_wall_to_pop);
}
