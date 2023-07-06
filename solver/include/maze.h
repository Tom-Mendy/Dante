/*
** EPITECH PROJECT, 2023
** maze
** File description:
** maze
*/

#ifndef MAZE_H_
    #define MAZE_H_
    typedef struct maze {
        int x;
        int y;
        int cost;
        struct maze *previous_case;
        struct maze *next;
    } maze_t;

#endif /* !MAZE_H_ */
