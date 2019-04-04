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

    FAIL_IF(!tile, NULL);
    if (tile->down && tile->down->visited)
        tiles[0] = tile->down;
    if (tile->up && tile->up->visited)
        tiles[1] = tile->up;
    if (tile->right && tile->right->visited)
        tiles[2] = tile->right;
    if (tile->left && tile->left->visited)
        tiles[3] = tile->left;
    FAIL_IF(!tiles[0] && !tiles[1] && !tiles[2] && !tiles[3], NULL);
    while (nbr == -1 || tiles[nbr] == NULL) {
        nbr = random_nbr(0, 3);
        if (nbr < 0 || nbr > 3)
            return (NULL);
    }
    return (tiles[nbr]);
}

static int check_wall_neighbor(tile_t *tile)
{
    int n = 0;

    FAIL_IF(!tile || tile->type != 'X', 0);
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

void destroy_random_walls(tile_t *maze, vector_t size)
{
    int n = 0;
    int nb_tiles = (size.x * size.y) / 10;

    FAIL_IF_VOID(!maze);
    maze->visited = 0;
    while (maze && !check_wall_neighbor(maze)) {
        n = random_nbr(nb_tiles / 2, nb_tiles);
        while (maze && n > 0) {
            maze = random_move(maze);
            --n;
        }
        if (maze)
            maze->visited = 0;
    }
    if (maze)
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
        destroy_random_walls(maze, size);
        ++n;
    }
    while (maze && maze->right)
        maze = maze->right;
    while (maze && maze->down)
        maze = maze->down;
    while (n > 1) {
        destroy_random_walls(maze, size);
        --n;
    }
}