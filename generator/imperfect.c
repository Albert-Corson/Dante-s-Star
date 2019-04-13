/*
** EPITECH PROJECT, 2019
** dante
** File description:
** imperfect
*/

#include "generator.h"

static tile_t *random_vert(tile_t *tile)
{
    int i = -1;
    tile_t *tiles[2] = {NULL, NULL};

    if (tile && tile->down && tile->down->visited) {
        ++i;
        tiles[i] = tile->down;
    }
    if (tile && tile->up && tile->up->visited) {
        ++i;
        tiles[i] = tile->up;
    }
    FAIL_IF(i == -1, NULL);
    return (tiles[random_nbr(0, i)]);
}

static tile_t *random_hori(tile_t *tile)
{
    int i = -1;
    tile_t *tiles[2] = {NULL, NULL};

    if (tile && tile->left && tile->left->visited) {
        ++i;
        tiles[i] = tile->left;
    }
    if (tile && tile->right && tile->right->visited) {
        ++i;
        tiles[i] = tile->right;
    }
    FAIL_IF(i == -1, NULL);
    return (tiles[random_nbr(0, i)]);
}

static int check_wall_neighbor(tile_t *tile)
{
    int n = 0;

    FAIL_IF(!tile || tile->type != 'X', 0);
    if (tile->down && tile->down->type != 'X')
        ++n;
    if (tile->up && tile->up->type != 'X')
        ++n;
    if (tile->left && tile->left->type != 'X')
        ++n;
    if (tile->right && tile->right->type != 'X')
        ++n;
    if (n >= 2)
        return (1);
    return (0);
}

tile_t *destroy_random_wall(tile_t *maze, vector_t size)
{
    int n = 0;

    FAIL_IF(!maze, NULL);
    maze->visited = 0;
    while (maze && !check_wall_neighbor(maze)) {
        n = random_nbr(size.x * 0.15, size.x * 0.4);
        while (maze && n > 0) {
            maze = random_hori(maze);
            --n;
        }
        n = random_nbr(size.y * 0.15, size.y * 0.4);
        while (maze && n > 0) {
            maze = random_vert(maze);
            --n;
        }
        if (maze)
            maze->visited = 0;
    }
    if (maze)
        maze->type = '*';
    return (maze);
}

void imperfect_maze(tile_t *maze, vector_t size)
{
    tile_t *tmp = NULL;
    int nb_tiles = (size.x * size.y) * 0.07;
    int n = 0;

    while (n <= nb_tiles) {
        tmp = destroy_random_wall(maze, size);
        maze = tmp ? tmp : maze;
        ++n;
    }
    while (maze && maze->right)
        maze = maze->right;
    while (maze && maze->down)
        maze = maze->down;
    maze->up->type = '*';
    maze->left->type = '*';
    maze->left->up->type = '*';
    while (n > 0) {
        tmp = destroy_random_wall(maze, size);
        maze = tmp ? tmp : maze;
        --n;
    }
}