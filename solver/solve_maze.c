/*
** EPITECH PROJECT, 2019
** dante
** File description:
** solve_maze
*/

#include "solver.h"

int move_down(char **maze, vector_t from, vector_t size)
{
    FAIL_IF(from.y + 1 >= size.y, 0);
    FAIL_IF(maze[from.y + 1][from.x] != '*', 0);
    return (solve_maze(maze, VECT(from.x, from.y + 1), size));
}

int move_up(char **maze, vector_t from, vector_t size)
{
    FAIL_IF(from.y - 1 < 0, 0);
    FAIL_IF(maze[from.y - 1][from.x] != '*', 0);
    return (solve_maze(maze, VECT(from.x, from.y - 1), size));
}

int move_left(char **maze, vector_t from, vector_t size)
{
    FAIL_IF(from.x - 1 < 0, 0);
    FAIL_IF(maze[from.y][from.x - 1] != '*', 0);
    return (solve_maze(maze, VECT(from.x - 1, from.y), size));
}

int move_right(char **maze, vector_t from, vector_t size)
{
    FAIL_IF(from.x + 1 >= size.x, 0);
    FAIL_IF(maze[from.y][from.x + 1] != '*', 0);
    return (solve_maze(maze, VECT(from.x + 1, from.y), size));
}

int solve_maze(char **maze, vector_t pos, vector_t size)
{
    maze[pos.y][pos.x] = 'o';
    FAIL_IF(pos.x + 1 >= size.x && pos.y + 1 >= size.y, 1);
    if (move_up(maze, pos, size))
        return (1);
    if (move_down(maze, pos, size))
        return (1);
    if (move_left(maze, pos, size))
        return (1);
    if (move_right(maze, pos, size))
        return (1);
    maze[pos.y][pos.x] = '*';
    return (0);
}