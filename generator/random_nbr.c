/*
** EPITECH PROJECT, 2019
** dante
** File description:
** random_nbr
*/

#include "generator.h"

int random_nbr(int min, int max)
{
    return (((float)rand() / RAND_MAX) * ((max - min) + 1) + min);
}