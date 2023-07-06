/*
** EPITECH PROJECT, 2023
** maze_sulotion
** File description:
** maze_solution
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "solver_header.h"
#include "vector.h"
#include "maze.h"
#include "lists.h"
#include "my.h"

maze_t *first_step(char **map, maze_t *neighbor_list)
{
    if (map[0][1] != '\0' && map[0][1] != 'X') {
        map[0][1] = 'N';
        neighbor_list = add_maze_case_in_list(neighbor_list,
        (vector_t){.x = 1, .y = 0}, calcul_distance(1, 0, 0, 0) +
        calcul_distance(1, 0, my_strlen(map[0]) - 1, my_tablen(map)), NULL);
    }
    if (map[1] != NULL && map[1][0] != 'X') {
        map[1][0] = 'N';
        neighbor_list = add_maze_case_in_list(neighbor_list,
        (vector_t){.x = 0, .y = 1}, calcul_distance(0, 1, 0, 0) +
        calcul_distance(0, 1, my_strlen(map[0]) - 1, my_tablen(map)), NULL);
    }
    return neighbor_list;
}

void check_case(char **map, lists_t *lists)
{
    maze_t *list_tmp = lists->neighbor_list;
    maze_t *min = min_neighbor_distance(lists->neighbor_list);
    if (min == NULL)
        return;
    map[min->y][min->x] = 'C';
    if (min->x == lists->end_vector.x && min->y == lists->end_vector.y) {
        lists->finish = 1;
        lists->end = min;
    }
    delink_list(min, lists, list_tmp);
    list_tmp = lists->case_check_list;
    if (list_tmp != NULL) {
        while (list_tmp->next != NULL)
            list_tmp = list_tmp->next;
        list_tmp->next = min;
    } else
        lists->case_check_list = min;
    lists->neighbor_list = check_neighbor(map, lists->neighbor_list, min);
}

void clear_and_put_way_in_tab(char **map, lists_t *lists)
{
    clean_map(map);
    map[0][0] = 'o';
    while (lists->end->previous_case != NULL) {
        map[lists->end->y][lists->end->x] = 'o';
        lists->end = lists->end->previous_case;
    }
    if ((map[0][1] != '\0' && map[0][1] == '*' && map[0][2] == 'o') || (map[0]
    [1] == '*' && map[1] != NULL && map[1][0] == '*' && map[1][1] == 'o'))
        map[0][1] = 'o';
    if (map[1] != NULL && map[2] != NULL && map[1][0] == '*' &&
    map[2][0] == 'o' && map[0][1] != 'o')
        map[1][0] = 'o';
    if (map[1] != NULL && map[0][1] != '\0' && map[0][1] == 'o') {
        if (map[0][1] != 'X')
            map[0][1] = 'o';
        else
            map[1][0] = 'o';
    }
    free_list(lists->case_check_list);
    free_list(lists->neighbor_list);
}

char **astar(char **map)
{
    lists_t lists = {.case_check_list = NULL, .neighbor_list = NULL,
    .finish = 0};
    lists.end_vector.x = my_strlen(map[0]) - 1;
    lists.end_vector.y = my_tablen(map) - 1;
    lists.neighbor_list = first_step(map, lists.neighbor_list);
    if (lists.neighbor_list == NULL) {
        return NULL;
    }
    while (lists.neighbor_list != NULL) {
        check_case(map, &lists);
        if (lists.finish == 1) {
            clear_and_put_way_in_tab(map, &lists);
            return map;
        }
    }
    free_list(lists.case_check_list);
    free_list(lists.neighbor_list);
    return NULL;
}

int maze_solution(char **map)
{
    if (my_strlen(map[0]) == 1 && my_tablen(map) == 1) {
        free_tab(map);
        my_putstr("o");
        return OK;
    }
    if (astar(map) == NULL) {
        my_putstr("no solution found");
        free_tab(map);
        return OK;
    }
    for (int i = 0; map[i + 1] != NULL; i++) {
        my_putstr(map[i]);
        write(1, "\n", 1);
    }
    my_putstr(map[my_tablen(map) - 1]);
    free_tab(map);
    return OK;
}
