/*
** EPITECH PROJECT, 2023
** distance
** File description:
** distance
*/

#include <math.h>
#include "my.h"

int calcul_distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
