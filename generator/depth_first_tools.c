/*
** EPITECH PROJECT, 2019
** dante
** File description:
** depth_first
*/

#include "generator.h"

void set_visited(tile_t *tile, int *unvisited)
{
    FAIL_IF_VOID(!tile);
    if (!tile->visited) {
        tile->visited = 1;
        --*unvisited;
    }
    if (tile->down && !tile->down->visited) {
        tile->down->visited = 1;
        --*unvisited;
    }
    if (tile->right && !tile->right->visited) {
        tile->right->visited = 1;
        --*unvisited;
    }
    FAIL_IF_VOID(!tile->down || !tile->down->right);
    FAIL_IF_VOID(tile->down->right->visited);
    tile->down->right->visited = 1;
    --*unvisited;
}

void place_end_point(tile_t *maze)
{
    int x = 0;
    int y = 0;

    while (maze->right) {
        maze = maze->right;
        ++x;
    }
    while (maze->down) {
        maze = maze->down;
        ++y;
    }
    maze->type = '*';
    if (x % 2 != 0)
        maze = maze->left;
    maze->type = '*';
    if (y % 2 != 0)
        maze = maze->up;
    maze->type = '*';
}

void init_tile(tile_t *tile)
{
    FAIL_IF_VOID(!tile);
    tile->type = '*';
}

int neighbor_unvisited(tile_t *tile)
{
    FAIL_IF(!tile, 0);
    if (tile->right && tile->right->right && !tile->right->right->visited)
        return (1);
    if (tile->down && tile->down->down && !tile->down->down->visited)
        return (1);
    if (tile->left && tile->left->left && !tile->left->left->visited)
        return (1);
    if (tile->up && tile->up->up && !tile->up->up->visited)
        return (1);
    return (0);
}