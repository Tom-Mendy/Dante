/*
** EPITECH PROJECT, 2023
** create elem
** File description:
** create_elem
*/

#include <stddef.h>
#include <stdlib.h>
#include "maze.h"
#include "vector.h"

maze_t *create_maze_case(vector_t vector, int cost, maze_t *previous)
{
    maze_t *case_tmp = malloc(sizeof(maze_t));
    if (case_tmp == NULL)
        return NULL;
    case_tmp->x = vector.x;
    case_tmp->y = vector.y;
    case_tmp->cost = cost;
    case_tmp->previous_case = previous;
    case_tmp->next = NULL;
    return case_tmp;
}
