/*
** EPITECH PROJECT, 2019
** dante
** File description:
** get_maze
*/

#include "solver.h"

void maze_add_line(maze_str_t **maze, char *str)
{
    maze_str_t *new = NULL;
    maze_str_t *tmp = *maze;

    FAIL_IF_VOID(!str);
    new = malloc(sizeof(*new));
    new->str = my_copycat(NULL, str, get_char_pos(str, '\n'));
    new->next = NULL;
    if (!*maze) {
        *maze = new;
        return;
    }
    int i = 0;
    while (tmp->next) {
        tmp = tmp->next;
        i++;
    }
    tmp->next = new;
}

void maze_str_destroy(maze_str_t *maze)
{
    maze_str_t *next = maze ? maze->next : NULL;

    while (next) {
        free(maze);
        maze = next;
        next = next->next;
    }
    free(maze);
}

char **get_maze_arr(maze_str_t *maze)
{
    char **ret = NULL;
    maze_str_t *tmp = maze;
    int size = 0;
    int i = 0;

    while (tmp) {
        tmp = tmp->next;
        ++size;
    }
    ret = malloc(sizeof(char *) * (size + 1));
    while (i < size) {
        ret[i] = maze->str;
        ++i;
        maze = maze->next;
    }
    ret[i] = NULL;
    return (ret);
}

char **get_maze(const char *path)
{
    maze_str_t *list = NULL;
    FILE *fd = fopen(path, "r");
    char *str = NULL;
    int rd = 1;
    size_t n = 0;
    char **maze = NULL;

    FAIL_IF(!fd, NULL);
    while ((rd = getline(&str, &n, fd)) != -1)
        maze_add_line(&list, str);
    free(str);
    fclose(fd);
    maze = get_maze_arr(list);
    maze_str_destroy(list);
    return (maze);
}

vector_t verify_maze(char **maze)
{
    size_t len = strlen(maze[0]);
    int y = 0;
    int x = 0;
    vector_t ret = VECT(len, -1);

    while (maze[y]) {
        x = 0;
        while (maze[y][x] == '*' || maze[y][x] == 'X')
            ++x;
        if (maze[y][x] != '*' && maze[y][x] != 'X' && maze[y][x] != '\0')
            return (ret);
        if (x == 0 && !maze[y + 1])
            return (VECT(len, y));
        else if (x != (int)len)
            return (ret);
        ++y;
    }
    ret.y = y;
    return (ret);
}