/*
** EPITECH PROJECT, 2019
** dante
** File description:
** imperfect
*/

#include "generator.h"

static tile_t *random_move(tile_t *tile)
{
    int nbr = -1;
    tile_t *tiles[4] = {NULL, NULL, NULL, NULL};

    if (tile->down)
        tiles[0] = tile->down;
    if (tile->up)
        tiles[1] = tile->up;
    if (tile->right)
        tiles[2] = tile->right;
    if (tile->left)
        tiles[3] = tile->left;
    while (nbr == -1 || tiles[nbr] == NULL)
        nbr = random_nbr(0, 3);
    return (tiles[nbr]);
}

static int check_wall_neighbor(tile_t *tile)
{
    int n = 0;

    FAIL_IF(tile->type != 'X', 0);
    if (tile->down && tile->down->type == '*')
        ++n;
    if (tile->up && tile->up->type == '*')
        ++n;
    if (tile->left && tile->left->type == '*')
        ++n;
    if (tile->right && tile->right->type == '*')
        ++n;
    if (n >= 2)
        return (1);
    return (0);
}

void destroy_random_walls(tile_t *maze)
{
    int n = 10;

    while (!check_wall_neighbor(maze)) {
        while (n > 0) {
            maze = random_move(maze);
            --n;
        }
        n = random_nbr(20, 30);
    }
    maze->type = '*';
}

void imperfect_maze(tile_t *maze, vector_t size)
{
    int nb_tiles = size.x * size.y;
    int n = 0;

    depth_first(maze, nb_tiles);
    FAIL_IF_VOID(size.x == 1 || size.y == 1);
    nb_tiles /= 60;
    while (n <= nb_tiles) {
        destroy_random_walls(maze);
        ++n;
    }
    while (maze->right)
        maze = maze->right;
    while (maze->down)
        maze = maze->down;
    while (n > 1) {
        destroy_random_walls(maze);
        --n;
    }
}