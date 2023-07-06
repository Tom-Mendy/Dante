/*
** EPITECH PROJECT, 2023
** my_listlen
** File description:
** my_listlen
*/

#include <unistd.h>
#include "maze.h"

int my_listlen(maze_t *list)
{
    int nb = 0;
    maze_t *list_tmp = list;
    while (list_tmp != NULL) {
        nb++;
        list_tmp = list_tmp->next;
    }
    return nb;
}
