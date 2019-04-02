/*
** EPITECH PROJECT, 2019
** dante
** File description:
** maze_init
*/

#include "generator.h"

void append_tile_hor(tile_t **list, tile_t *new)
{
    tile_t *tile = *list;

    FAIL_IF_VOID(!new);
    if (!tile) {
        *list = new;
        return;
    }
    while (tile && tile->right)
        tile = tile->right;
    tile->right = new;
    new->left = tile;
}

void append_tile_vert(tile_t **list, tile_t *new)
{
    tile_t *tile = *list;

    FAIL_IF_VOID(!new);
    if (!tile) {
        *list = new;
        return;
    }
    while (tile && tile->down)
        tile = tile->down;
    tile->down = new;
    new->up = tile;
}

tile_t *tile_new(char type)
{
    tile_t *new = malloc(sizeof(tile_t));

    new->type = type;
    new->visited = 0;
    new->up = NULL;
    new->down = NULL;
    new->left = NULL;
    new->right = NULL;
    return (new);
}

tile_t *maze_create_row(int size, tile_t *upper)
{
    int x = 0;
    tile_t *ret = NULL;
    tile_t *tile = NULL;

    while (x < size) {
        tile = tile_new('X');
        append_tile_hor(&ret, tile);
        if (upper) {
            append_tile_vert(&upper, tile);
            upper = upper->right;
        }
        ++x;
    }
    return (ret);
}

tile_t *maze_init(vector_t size)
{
    tile_t *above = NULL;
    tile_t *layer = NULL;
    tile_t *maze = NULL;
    int y = 0;

    while (y < size.y) {
        above = layer;
        layer = maze_create_row(size.x, above);
        if (y == 0)
            maze = layer;
        ++y;
    }
    return (maze);
}