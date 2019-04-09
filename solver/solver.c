/*
** EPITECH PROJECT, 2019
** my_solver
** File description:
** solver
*/

#include "solver.h"

int	pars_map(int x, int y, map_t *map, int i)
{
    map->map[y][x] = 'o';
    if (i == 174467)
        return (-1);
    if (x == map->width - 1 && y == map->height - 1)
        return (0);
    if (x + 1 < map->width && map->map[y][x + 1] == '*')
        if (pars_map(x + 1, y, map, i + 1) == 0)
            return (0);
    if (y + 1 < map->height && map->map[y + 1][x] == '*')
        if (pars_map(x, y + 1, map, i + 1) == 0)
            return (0);
    if (x - 1 >= 0 && map->map[y][x - 1] == '*')
        if (pars_map(x - 1, y, map, i + 1) == 0)
            return (0);
    if (y - 1 >= 0 && map->map[y - 1][x] == '*')
        if (pars_map(x, y - 1, map, i + 1) == 0)
            return (0);
    map->map[y][x] = 'a';
    return (-1);
}

void change_map(map_t *map)
{
    int	x;
    int y = 0;

    while (y != map->height) {
        x = 0;
        while (x != map->width) {
            map->map[y][x] = map->map[y][x] == 'a' ? '*' : map->map[y][x];
            x = x + 1;
        }
        y = y + 1;
    }
}