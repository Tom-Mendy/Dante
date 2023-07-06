/*
** EPITECH PROJECT, 2023
** lists.h
** File description:
** lists
*/

#include "vector.h"
#include "maze.h"

#ifndef LISTS_H_
    #define LISTS_H_
    typedef struct lists {
        int finish;
        vector_t end_vector;
        maze_t *end;
        maze_t *neighbor_list;
        maze_t *case_check_list;
    } lists_t;

#endif /* !LISTS_H_ */
