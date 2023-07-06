/*
** EPITECH PROJECT, 2023
** print_list
** File description:
** print_list
*/

#include <unistd.h>
#include "maze.h"
#include "my.h"

void print_list(maze_t *list)
{
    maze_t *list_tmp = list;
    while (list_tmp != NULL) {
        my_printf("x: %d | y: %d\n", list->x, list->y);
        list_tmp = list_tmp->next;
    }
}
