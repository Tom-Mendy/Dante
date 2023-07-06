/*
** EPITECH PROJECT, 2023
** delink_list
** File description:
** delink_list
*/

#include <unistd.h>
#include "lists.h"
#include "solver_header.h"
#include "my.h"
#include "maze.h"

static maze_t *previous_min_case(maze_t *min, maze_t *list_tmp)
{
    while (list_tmp->next != NULL && list_tmp->next != min)
                list_tmp = list_tmp->next;
    return list_tmp;
}

void delink_list(maze_t *min, lists_t *lists, maze_t *list_tmp)
{
    if (list_tmp->next == NULL) {
        lists->neighbor_list = NULL;
    } else {
        if (list_tmp == min) {
            lists->neighbor_list = lists->neighbor_list->next;
            min->next = NULL;
        } else {
            list_tmp = previous_min_case(min , list_tmp);
            list_tmp->next = min->next;
            min->next = NULL;
        }
    }
}
