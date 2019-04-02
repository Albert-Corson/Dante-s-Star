/*
** EPITECH PROJECT, 2019
** dante
** File description:
** depth_first
*/

#include "generator.h"

tile_t *random_neighbor(tile_t *tile)
{
    int nbr = -1;
    tile_t *tiles[4] = {NULL, NULL, NULL, NULL};
    tile_t *path[4] = {tile->down, tile->up, tile->right, tile->left};

    if (tile->down && tile->down->down && !tile->down->down->visited)
        tiles[0] = tile->down->down;
    if (tile->up && tile->up->up && !tile->up->up->visited)
        tiles[1] = tile->up->up;
    if (tile->right && tile->right->right && !tile->right->right->visited)
        tiles[2] = tile->right->right;
    if (tile->left && tile->left->left && !tile->left->left->visited)
        tiles[3] = tile->left->left;
    while (nbr == -1 || tiles[nbr] == NULL)
        nbr = random_nbr(0, 3);
    if (path[nbr])
        path[nbr]->type = '*';
    return (tiles[nbr]);
}

void depth_first(tile_t *maze, int nb_tiles)
{
    stack_t *stack = NULL;

    init_tile(maze);
    place_end_point(maze);
    while (nb_tiles > 0) {
        set_visited(maze, &nb_tiles);
        if (!neighbor_unvisited(maze)) {
            stack_pop(&stack);
            maze = stack ? stack->tile : maze;
        } else {
            stack_push(&stack, maze);
            maze = random_neighbor(maze);
            init_tile(maze);
        }
    }
    stack_destroy(stack);
}