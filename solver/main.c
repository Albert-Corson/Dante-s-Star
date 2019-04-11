/*
** EPITECH PROJECT, 2019
** Dante-star
** File description:
** main
*/

#include "solver.h"

int main(int argc, const char **argv)
{
    char **maze = NULL;
    vector_t size;

    FAIL_IF(argc != 2, 84);
    maze = get_maze(argv[1]);
    FAIL_IF(!maze, 84);
    size = verify_maze(maze);
    FAIL_IF(size.x <= 0 || size.y <= 0, 84);
    if (solve_maze(maze, size))
        display_table(maze);
    else
        printf("no solution found");
    destroy_table(maze);
    return (0);
}