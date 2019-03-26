/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** destroy_table
*/

#include "my.h"

void destroy_table(char **table)
{
    int i = 0;

    if (!table)
        return;
    while (table[i]) {
        free(table[i]);
        ++i;
    }
    free(table);
}