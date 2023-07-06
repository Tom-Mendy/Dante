/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** generate_labyrinth
*/

#include "generator_header.h"

static int next_node_and_next_next_node_in_map(cells_t actual_next,
cells_t actual_next_next, cells_t map_dimention, char **maze)
{
    return (actual_next.x >= 0 && actual_next.x < map_dimention.x &&
    actual_next.y >= 0 && actual_next.y < map_dimention.y &&
    maze[actual_next.y][actual_next.x] == 'X') && (
    actual_next_next.x >= 0 && actual_next_next.x < map_dimention.x &&
    actual_next_next.y >= 0 && actual_next_next.y < map_dimention.y &&
    maze[actual_next_next.y][actual_next_next.x] == 'X');
}

static int generate_maze(char **maze, cells_t actual_cell,
cells_t map_dimention, cells_t *directions_coordinates)
{
    shuffle_cells_tab(directions_coordinates, 4);
    for (int i = 0; i < 4;) {
        cells_t actual_next = create_cells(actual_cell.x +
        directions_coordinates[i].x, actual_cell.y +
        directions_coordinates[i].y);
        cells_t actual_next_next = create_cells(actual_cell.x + (2 *
        directions_coordinates[i].x), actual_cell.y + (2 *
        directions_coordinates[i].y));
        if (next_node_and_next_next_node_in_map(actual_next, actual_next_next,
        map_dimention, maze) == 1) {
            maze[actual_next.y][actual_next.x] = '*';
            maze[actual_next_next.y][actual_next_next.x] = '*';
            actual_cell = actual_next_next;
            shuffle_cells_tab(directions_coordinates, 4);
            i = 0;
        } else
            i = i + 1;
    }
    return 0;
}

int generate_labyrinth(char **maze, int const x, int const y)
{
    maze[0][0] = '*';
    cells_t *directions_coordinates = generate_directions_coordinates();
    if (directions_coordinates == NULL)
        return KO;
    cells_t map_dimention = create_cells(x, y);
    shuffle_cells_tab(directions_coordinates, 4);
    cells_t actual_cell = create_cells(0, 0);
    generate_maze(maze, actual_cell, map_dimention, directions_coordinates);
    for (actual_cell.y = 0; actual_cell.y < y; actual_cell.y += 2) {
        for (actual_cell.x = 0; actual_cell.x < x; actual_cell.x += 2) {
            generate_maze(maze, actual_cell, map_dimention,
            directions_coordinates);
        }
    }
    free(directions_coordinates);
    maze[y - 1][x - 1] = '*';
    if (y != 1 && x != 1)
        maze[y - 1][x - 2] = '*';
    return OK;
}
