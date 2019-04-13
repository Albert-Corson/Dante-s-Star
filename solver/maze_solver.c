/*
** EPITECH PROJECT, 2019
** my_solver
** File description:
** solver
*/

#include "solver.h"

int try_dir(int **visited, vector_t size, vector_t pos, stack_t **stack)
{
    FAIL_IF(pos.y < 0 || pos.y >= size.y, 0);
    FAIL_IF(pos.x < 0 || pos.x >= size.x, 0);
    FAIL_IF(visited[pos.y][pos.x], 0);
    stack_push(stack, pos);
    return (1);
}

int **init_visited(char ** maze, vector_t size)
{
    int y = 0;
    int x = 0;
    int **visited = malloc(sizeof(int *) * (size.y + 1));

    while (y < size.y) {
        x = 0;
        visited[y] = malloc(sizeof(int) * size.x);
        while (x < size.x) {
            visited[y][x] = maze[y][x] == '*' ? 0 : 1;
            ++x;
        }
        ++y;
    }
    visited[y] = NULL;
    return (visited);
}

int is_neighbor(vector_t curr, stack_t *try)
{
    int x = curr.x - try->pos.x;
    int y = curr.y - try->pos.y;

    FAIL_IF(abs(x) + abs(y) != 1, 0);
    return (1);
}

int put_path(char **maze, stack_t *stack, vector_t size)
{
    vector_t curr;

    FAIL_IF(!stack, 0);
    curr = VECT(stack->pos.x, stack->pos.y);
    maze[curr.y][curr.x] = 'o';
    while (stack) {
        while (stack && !is_neighbor(curr, stack))
            curr = stack_pop(&stack);
        curr = stack_pop(&stack);
        maze[curr.y][curr.x] = 'o';
    }
    maze[size.y - 1][size.x - 1] = 'o';
    return (1);
}

int solve_maze(char **maze, vector_t size)
{
    stack_t *stack = NULL;
    vector_t curr = VECT(0, 0);
    int **visited = init_visited(maze, size);
    int i = 0;

    FAIL_IF(maze[size.y - 1][size.x - 1] != '*', 0);
    stack_push(&stack, curr);
    while (stack && !is_neighbor(VECT(size.x - 1, size.y - 1), stack)) {
        curr = stack->pos;
        visited[curr.y][curr.x] = 1;
        i += try_dir(visited, size, VECT(curr.x + 1, curr.y), &stack);
        i += try_dir(visited, size, VECT(curr.x - 1, curr.y), &stack);
        i += try_dir(visited, size, VECT(curr.x, curr.y + 1), &stack);
        i += try_dir(visited, size, VECT(curr.x, curr.y - 1), &stack);
        if (!i)
            stack_pop(&stack);
        i = 0;
    }
    destroy_table((char **)visited);
    return (put_path(maze, stack, size));
}