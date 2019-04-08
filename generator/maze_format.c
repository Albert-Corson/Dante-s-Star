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

    depth_first(maze, size.x * size.y);
    if (!perfect && size.x > 1 && size.y > 1)
        imperfect_maze(maze, size);
    return (maze);
}