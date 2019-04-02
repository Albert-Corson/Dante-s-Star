/*
** EPITECH PROJECT, 2019
** dante
** File description:
** display_maze
*/

#include "generator.h"

void display_maze(tile_t *maze)
{
    tile_t *line = NULL;

    while (maze) {
        line = maze;
        while (line) {
            my_putchar(line->type);
            line = line->right;
        }
        my_putchar('\n');
        maze = maze->down;
    }
}