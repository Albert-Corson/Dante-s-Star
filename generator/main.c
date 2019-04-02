/*
** EPITECH PROJECT, 2019
** Dante-star
** File description:
** main
*/

#include "dante.h"

int main(int argc, const char **argv)
{
    vector_t size;
    tile_t *maze = NULL;

    srand(time(0));
    FAIL_IF(argc < 3 || argc > 4, 84);
    FAIL_IF(!my_nisnum(argv[1], -1) || !my_nisnum(argv[2], -1), 84);
    size = VECT(my_getnbr(argv[1]), my_getnbr(argv[2]));
    FAIL_IF(size.x <= 0 || size.y <= 0, 84);
    FAIL_IF(argc == 4 && strcmp("perfect", argv[3]) != 0, 84);
    maze = maze_format(size, (argc == 4));
    display_maze(maze);
    destroy_maze(maze);
    return (0);
}