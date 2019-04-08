/*
** EPITECH PROJECT, 2019
** dante
** File description:
** depth_first
*/

#include "generator.h"

static int fill_tiles(tile_t *tiles[], tile_t *tile)
{
    int i = -1;

    if (tile->down && tile->down->down && !tile->down->down->visited) {
        ++i;
        tiles[i] = tile->down->down;
    }
    if (tile->up && tile->up->up && !tile->up->up->visited) {
        ++i;
        tiles[i] = tile->up->up;
    }
    if (tile->right && tile->right->right && !tile->right->right->visited) {
        ++i;
        tiles[i] = tile->right->right;
    }
    if (tile->left && tile->left->left && !tile->left->left->visited) {
        ++i;
        tiles[i] = tile->left->left;
    }
    return (i);
}

static void fill_path(tile_t *path[], tile_t *tile)
{
    int i = -1;

    if (tile->down && tile->down->down && !tile->down->down->visited) {
        ++i;
        path[i] = tile->down;
    }
    if (tile->up && tile->up->up && !tile->up->up->visited) {
        ++i;
        path[i] = tile->up;
    }
    if (tile->right && tile->right->right && !tile->right->right->visited) {
        ++i;
        path[i] = tile->right;
    }
    if (tile->left && tile->left->left && !tile->left->left->visited) {
        ++i;
        path[i] = tile->left;
    }
}

tile_t *random_neighbor(tile_t *tile)
{
    int i = -1;
    tile_t *tiles[4] = {NULL, NULL, NULL, NULL};
    tile_t *path[4] = {NULL, NULL, NULL, NULL};

    i = fill_tiles(tiles, tile);
    fill_path(path, tile);
    FAIL_IF(i == -1, NULL);
    i = random_nbr(0, i);
    if (path[i])
        path[i]->type = '*';
    return (tiles[i]);
}

void depth_first(tile_t *maze, int nb_tiles)
{
    stack_t *stack = NULL;

    init_tile(maze);
    while (maze && nb_tiles > 0) {
        set_visited(maze, &nb_tiles);
        if (!neighbor_unvisited(maze)) {
            stack_pop(&stack);
            maze = stack ? stack->tile : NULL;
        } else {
            stack_push(&stack, maze);
            maze = random_neighbor(maze);
            init_tile(maze);
        }
    }
    stack_destroy(stack);
}