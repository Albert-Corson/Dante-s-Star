/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** dante star
*/

#ifndef DANTE_H_
    #define DANTE_H_

#include "my.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct tile_s tile_t;
typedef struct vector_s vector_t;

struct tile_s {
    int visited;
    char type;
    tile_t *up;
    tile_t *down;
    tile_t *left;
    tile_t *right;
};

struct vector_s {
    int x;
    int y;
};

// GENERATOR
tile_t *maze_format(vector_t size, int perfect);
void display_maze(tile_t *maze);
tile_t *maze_init(vector_t size);
void destroy_maze(tile_t *maze);

// SOLVER

#define VECT(x, y) (vector_t){x, y}
#define FAIL_IF(cond, ret) if (cond) return (ret)
#define FAIL_IF_VOID(cond) if (cond) return

#endif /* !DANTE_H_ */