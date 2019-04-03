/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** dante star
*/

#ifndef SOLVE_H_
    #define SOLVE_H_

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef struct maze_str_s {
    char *str;
    struct maze_str_s *next;
} maze_str_t;

typedef struct vector_s {
    int x;
    int y;
} vector_t;

char **get_maze(const char *path);
vector_t verify_maze(char **maze);
int solve_maze(char **maze, vector_t pos, vector_t size);

#define VECT(x, y) (vector_t){x, y}
#define FAIL_IF(cond, ret) if (cond) return (ret)
#define FAIL_IF_VOID(cond) if (cond) return

#endif /* !SOLVE_H_ */