/*
** EPITECH PROJECT, 2023
** my_scripts
** File description:
** main
*/

#include "generator_header.h"

int main(int const ac, char const * const * const av)
{
    if (error(ac, av) == KO){
        help();
        return KO;
    }
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    if (x < 1 || y < 1)
        return 84;
    int perfect = 0;
    if (av[3] != NULL){
        perfect = strcmp(av[3], "perfect");
        if (perfect == 0)
            perfect = 1;
    }
    return generator(x, y, perfect);
}
