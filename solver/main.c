/*
** EPITECH PROJECT, 2019
** Dante-star
** File description:
** main
*/

#include "solver.h"

void display_maze(char **table)
{
    int i = 0;
    int n = 0;

    if (!table)
        return;
    while (table[i]) {
        if (table[i][n] == 'o') {
            my_putstr("\x1b[31m");
            my_putchar(table[i][n]);
            my_putstr("\x1b[0m");
        } else
            my_putchar(table[i][n]);
        ++n;
        if (!table[i][n]) {
            n = 0;
            my_putchar('\n');
            ++i;
        }
    }
}

int main(int argc, const char **argv)
{
    vector_t size;
    char **maze = NULL;

    FAIL_IF(argc != 2, 84);
    maze = get_maze(argv[1]);
    FAIL_IF(!maze, 84);
    size = verify_maze(maze);
    FAIL_IF(size.x <= 0 || size.y <= 0, 84);
    solve_maze(maze, VECT(0, 0), size);
    display_table(maze);
    destroy_table(maze);
    return (0);
}