/*
** EPITECH PROJECT, 2019
** Dante-star
** File description:
** main
*/

#include "dante.h"

char **init_maze(vector_t size)
{
    int x = 0;
    int y = 0;
    char **maze = malloc(sizeof(char *) * (size.y + 1));

    FAIL_IF(!maze, NULL);
    while (y < size.y) {
        maze[y] = malloc(sizeof(char) * (size.x + 1));
        while (x < size.x) {
            maze[y][x] = 42;
            ++x;
        }
        maze[y][x] = 0;
        x = 0;
        y++;
    }
    maze[size.y] = NULL;
    return (maze);
}

int main(int argc, const char **argv)
{
    vector_t size;
    char **maze = NULL;

    FAIL_IF(argc < 3 || argc > 4, 84);
    FAIL_IF(!my_nisnum(argv[1], -1) || !my_nisnum(argv[2], -1), 84);
    size = VECT(my_getnbr(argv[1]), my_getnbr(argv[2]));
    FAIL_IF(size.x <= 0 || size.y <= 0, 84);
    maze = init_maze(size);
    display_table(maze);
    destroy_table(maze);
    return (0);
}