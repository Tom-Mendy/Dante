/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** error
*/

#include "generator_header.h"

int error(int const ac, char const * const * const av)
{
    if (av == NULL || (ac != 3 && ac != 4))
        return KO;
    if (my_str_is_num(av[1]) == false || my_str_is_num(av[2]) == false)
        return KO;
    if (av[3] != NULL)
        if (strcmp(av[3], "perfect") != 0)
            return KO;
    return OK;
}
