/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-arthur.gauffre
** File description:
** help
*/

#include "generator_header.h"

int help(void)
{
    if (write(2, "try : ./generator x y [perfect]\n", 33) == -1)
        return KO;
    return OK;
}
