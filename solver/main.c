/*
** EPITECH PROJECT, 2019
** Dante-star
** File description:
** main
*/

#include "solver.h"

int main(int argc, const char **argv)
{
    map_t map;
    vector_t size;

    FAIL_IF(argc != 2, 84);
    map.map = get_maze(argv[1]);
    FAIL_IF(!map.map, 84);
    size = verify_maze(map.map);
    map.height = size.y;
    map.width = size.x;
    FAIL_IF(size.x <= 0 || size.y <= 0, 84);
    if (pars_map(0, 0, &map, 0) == -1) {
        printf("no solution found\n");
        return (0);
    }
    change_map(&map);
    // solve_maze(maze, VECT(0, 0), size);
    display_table(map.map);
    destroy_table(map.map);
    return (0);
}