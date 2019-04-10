/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** dante star
*/

#ifndef SOLVE_H_
#define SOLVE_H_

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

typedef struct stack_s stack_t;
typedef struct vector_s vector_t;
typedef struct maze_str_s maze_str_t;

struct vector_s {
    int x;
    int y;
};

struct maze_str_s {
    char *str;
    maze_str_t *next;
};

struct stack_s {
    vector_t pos;
    stack_t *next;
};

// STACK
void stack_destroy(stack_t *stack);
vector_t stack_pop(stack_t **stack);
void stack_push(stack_t **stack, vector_t pos);

void display_table(char **table);
void destroy_table(char **table);
char *my_copycat(char *dest, char *src, int lim);
int get_char_pos(char const *str, char goal);

char **get_maze(const char *path);
vector_t verify_maze(char **maze);
int solve_maze(char **maze, vector_t size);

#define VECT(x, y) (vector_t){x, y}
#define FAIL_IF(cond, ret) if (cond) return (ret);
#define FAIL_IF_VOID(cond) if (cond) return;

#endif /* !SOLVE_H_ */