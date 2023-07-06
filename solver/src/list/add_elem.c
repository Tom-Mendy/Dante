/*
** EPITECH PROJECT, 2023
** add elem
** File description:
** add_elem
*/

#include <stddef.h>
#include "solver_header.h"
#include "vector.h"
#include "maze.h"

maze_t *add_maze_case_in_list(maze_t *list, vector_t vector, int cost,
maze_t *previous)
{
    maze_t *list_tmp = list;
    if (list == NULL) {
        list = create_maze_case(vector, cost, previous);
        return list;
    }
    while (list_tmp->next != NULL)
        list_tmp = list_tmp->next;
    list_tmp->next = create_maze_case(vector, cost, previous);
    return list;
}
