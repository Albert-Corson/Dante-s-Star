/*
** EPITECH PROJECT, 2019
** dante
** File description:
** maze_free
*/

#include "dante.h"

void destroy_maze_row(tile_t *row)
{
    tile_t *next = row ? row->right : NULL;

    while (next) {
        free(row);
        row = next;
        next = next->right;
    }
    free(row);
}

void destroy_maze(tile_t *maze)
{
    tile_t *down = maze ? maze->down : NULL;

    while (down) {
        destroy_maze_row(maze);
        maze = down;
        down = down->down;
    }
    destroy_maze_row(maze);
}