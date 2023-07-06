/*
** EPITECH PROJECT, 2023
** min_list
** File description:
** min_list
*/

#include <unistd.h>
#include "maze.h"

maze_t *min_neighbor_distance(maze_t *neighbor_list)
{
    maze_t *min = neighbor_list;
    maze_t *list_tmp = neighbor_list;
    while (list_tmp != NULL) {
        if (list_tmp->cost < min->cost) {
            min = list_tmp;
        }
        list_tmp = list_tmp->next;
    }
    return min;
}
