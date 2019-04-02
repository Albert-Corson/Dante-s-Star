/*
** EPITECH PROJECT, 2019
** dante generator
** File description:
** maze_format
*/

#include "generator.h"

tile_t *maze_format(vector_t size, int perfect)
{
    tile_t *maze = maze_init(size);

    if (!perfect)
        depth_first(maze, size.x * size.y);
    else
        depth_first(maze, size.x * size.y);
    return (maze);
}