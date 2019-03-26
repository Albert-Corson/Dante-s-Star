/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** display_table
*/

#include "my.h"

void display_table(char **table)
{
    int i = 0;

    if (!table)
        return;
    while (table[i]) {
        my_putstr(table[i]);
        my_putchar('\n');
        ++i;
    }
}