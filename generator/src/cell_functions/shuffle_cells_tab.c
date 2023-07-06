/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** shuffle_cells_tab
*/

#include "generator_header.h"

void shuffle_cells_tab(cells_t *directions_coordinates, int len_tab)
{
    for (int i = 0; i < len_tab; i++) {
        int random_index = rand() % len_tab;
        cells_t temp = directions_coordinates[i];
        directions_coordinates[i] = directions_coordinates[random_index];
        directions_coordinates[random_index] = temp;
    }
}
