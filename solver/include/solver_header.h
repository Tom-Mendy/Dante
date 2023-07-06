/*
** EPITECH PROJECT, 2023
** solver_header
** File description:
** solver_header
*/

#include "vector.h"
#include "lists.h"
#include "maze.h"

#ifndef SOLVER_HEADER_H_
    #define SOLVER_HEADER_H_
    #define KO 84
    #define OK 0

    char *file_not_valid(char const *filename);
    char **create_map(char *buffer);
    void free_tab(char **tab);
    int my_tablen(char **tab);
    maze_t *create_maze_case(vector_t vector, int cost, maze_t *previous);
    void free_list(maze_t *list);
    maze_t *add_maze_case_in_list(maze_t *list, vector_t vector, int cost,
    maze_t *previous);
    int maze_solution(char **map);
    void print_list(maze_t *list);
    int my_listlen(maze_t *list);
    int calcul_distance(int x1, int y1, int x2, int y2);
    maze_t *min_neighbor_distance(maze_t *neighbor_list);
    maze_t *check_neighbor(char **map, maze_t *neighbor_list,
    maze_t *case_check);
    void delink_list(maze_t *min, lists_t *lists,
    maze_t *list_tmp);
    void clean_map(char **map);

#endif /* !SOLVER_HEADER_H_ */
