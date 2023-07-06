/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** create_cells
*/

#include "generator_header.h"

cells_t create_cells(int x, int y)
{
    cells_t tmp_cells;
    tmp_cells.x = x;
    tmp_cells.y = y;
    return tmp_cells;
}
