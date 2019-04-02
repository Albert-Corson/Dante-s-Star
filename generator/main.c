/*
** EPITECH PROJECT, 2019
** Dante-star
** File description:
** main
*/

#include "generator.h"

int usage(void)
{
    my_puterror("./generator X Y [perfect]\n");
    my_puterror("\tThe values of X and Y represent the size of the maze\n");
    my_puterror("\tIf the third argument [perfect] is present, the path to");
    my_puterror("solve the maze will be unique\n");
    return (84);
}

int main(int argc, const char **argv)
{
    vector_t size;
    tile_t *maze = NULL;

    srand(time(NULL));
    FAIL_IF(argc < 3 || argc > 4, usage());
    FAIL_IF(!my_nisnum(argv[1], -1) || !my_nisnum(argv[2], -1), usage());
    size = VECT(my_getnbr(argv[1]), my_getnbr(argv[2]));
    FAIL_IF(size.x <= 0 || size.y <= 0, usage());
    FAIL_IF(argc == 4 && strcmp("perfect", argv[3]) != 0, usage());
    maze = maze_format(size, (argc == 4));
    display_maze(maze);
    destroy_maze(maze);
    return (0);
}