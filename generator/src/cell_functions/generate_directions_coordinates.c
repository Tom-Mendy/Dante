/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** generate_directions_coordinates
*/

#include "generator_header.h"

cells_t *generate_directions_coordinates(void)
{
    cells_t up = create_cells(0, -1);
    cells_t down = create_cells(0, 1);
    cells_t left = create_cells(-1, 0);
    cells_t right = create_cells(1, 0);
    cells_t *directions_coordinates = malloc(sizeof(cells_t) * (4));
    if (directions_coordinates == NULL)
        return NULL;
    directions_coordinates[0] = up;
    directions_coordinates[1] = down;
    directions_coordinates[2] = left;
    directions_coordinates[3] = right;
    return directions_coordinates;
}
