/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** dante star
*/

#ifndef GEN_H_
    #define GEN_H_

#include "my.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct tile_s tile_t;
typedef struct stack_s stack_t;
typedef struct vector_s vector_t;

struct stack_s {
    tile_t *tile;
    stack_t *next;
};

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

// MAZE
tile_t *maze_format(vector_t size, int perfect);
void display_maze(tile_t *maze);
tile_t *maze_init(vector_t size);
void destroy_maze(tile_t *maze);

// STACK
void stack_destroy(stack_t *stack);
void stack_pop(stack_t **stack);
void stack_push(stack_t **stack, tile_t *tile);

// TOOLS
int random_nbr(int min, int max);

// DEPTH FIRST
int neighbor_unvisited(tile_t *tile);
void init_tile(tile_t *tile);
void place_end_point(tile_t *maze);
void depth_first(tile_t *maze, int nb_tiles);
void set_visited(tile_t *tile, int *unvisited);

// IMPERFECT MAZE
void imperfect_maze(tile_t *maze, vector_t size);

#define VECT(x, y) (vector_t){x, y}
#define FAIL_IF(cond, ret) if (cond) return (ret)
#define FAIL_IF_VOID(cond) if (cond) return

#endif /* !GEN_H_ */