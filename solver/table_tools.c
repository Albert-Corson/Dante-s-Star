/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** destroy_table
*/

#include "solver.h"

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

void display_table(char **table)
{
    int i = 0;
    int len = 0;

    if (!table)
        return;
    len = strlen(table[i]);
    while (table[i]) {
        write(1, table[i], len);
        write(1, "\n", 1);
        ++i;
    }
}