/*
** EPITECH PROJECT, 2019
** dante
** File description:
** display_maze
*/

#include "generator.h"

void display_maze(tile_t *maze, vector_t size)
{
    int i = 0;
    tile_t *line = NULL;
    char *curr = malloc(sizeof(char) * (size.x + 1));

    while (maze) {
        line = maze;
        i = 0;
        while (line) {
            curr[i] = line->type;
            line = line->right;
            ++i;
        }
        write(1, curr, i);
        my_putchar('\n');
        maze = maze->down;
    }
    free(curr);
}