/*
** EPITECH PROJECT, 2019
** Dante-star
** File description:
** main
*/

#include "generator.h"

int usage(void)
{
    dprintf(2, "./generator X Y [perfect]\n");
    dprintf(2, "\tThe values of X and Y represent the size of the maze\n");
    dprintf(2, "\tIf the third argument [perfect] is present, the path to");
    dprintf(2, "solve the maze will be unique\n");
    return (84);
}

int my_nisnum(char const *str, int lim)
{
    int i = 0;

    while (str[i] && (i < lim || lim == -1)) {
        if (str[i] < 48 || str[i] > 57)
            return (0);
        ++i;
    }
    return (1);
}

int main(int argc, const char **argv)
{
    vector_t size;
    tile_t *maze = NULL;

    srand(time(NULL));
    FAIL_IF(argc < 3 || argc > 4, usage());
    FAIL_IF(!my_nisnum(argv[1], -1) || !my_nisnum(argv[2], -1), usage());
    size = VECT(atoi(argv[1]), atoi(argv[2]));
    FAIL_IF(size.x <= 0 || size.y <= 0, usage());
    FAIL_IF(argc == 4 && strcmp("perfect", argv[3]) != 0, usage());
    maze = maze_format(size, (argc == 4));
    display_maze(maze, size);
    destroy_maze(maze);
    return (0);
}