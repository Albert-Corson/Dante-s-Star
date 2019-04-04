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
    int tmp = min;
    int ret = 0;

    if (min > max) {
        min = max;
        max = tmp;
    }
    if (min == max)
        return (min);
    ret = ((float)rand() / RAND_MAX) * ((max - min) + 1) + min;
    ret = readjust_nb(ret, min, max);
    return (ret);
}