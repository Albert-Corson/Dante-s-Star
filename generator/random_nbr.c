/*
** EPITECH PROJECT, 2019
** dante
** File description:
** random_nbr
*/

#include "generator.h"

int readjust_nb(int nb, int min, int max)
{
    while (nb < min)
        nb -= (min - max) - 1;
    while (nb > max)
        nb += (min - max) - 1;
    return (nb);
}

int random_nbr(int min, int max)
{
    float n = (float)rand() / RAND_MAX;
    int tmp = min;

    if (min > max) {
        min = max;
        max = tmp;
    } else if (min == max)
        return (min);
    if (n >= 0.99999)
        return (max);
    return ((n * (max - min + 1) + min));
}