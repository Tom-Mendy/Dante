/*
** EPITECH PROJECT, 2023
** free_list
** File description:
** free_list
*/

#include <stddef.h>
#include <stdlib.h>
#include "maze.h"

void free_list(maze_t *list)
{
    maze_t *tmp = list;
    while (list != NULL) {
        list = list->next;
        free(tmp);
        tmp = list;
    }
}
