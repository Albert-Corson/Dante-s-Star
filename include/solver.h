/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** dante star
*/

#ifndef SOLVE_H_
    #define SOLVE_H_

#include "generator.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct maze_str_s {
    char *str;
    struct maze_str_s *next;
} maze_str_t;

typedef struct s_map {
    int height;
    int width;
    char **map;
} map_t;

char **get_maze(const char *path);
vector_t verify_maze(char **maze);
int solve_maze(char **maze, vector_t pos, vector_t size);
void display_table(char **table);
void destroy_table(char **table);
char *my_copycat(char *dest, char *src, int lim);
int get_char_pos(char const *str, char goal);

int	pars_map(int x, int y, map_t *map, int i);
void change_map(map_t *map);

#endif /* !SOLVE_H_ */