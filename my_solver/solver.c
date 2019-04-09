/*
** EPITECH PROJECT, 2019
** my_solver
** File description:
** solver
*/

#include "struct.h"

void print_map(t_map *map)
{
    int i = 0;

    while (i != map->hauteur) {
        printf("%s\n", map->map[i]);
        i = i + 1;
    }
}

int	detect_error(char *line, int largeur)
{
    int	i = 0;

    if ((int)strlen(line) != largeur)
        return (1);
    while (line[i] != '\0') {
        if (line[i] != '*' && line[i] != 'X')
	        return (1);
        i++;
    }
    return (0);
}

int	stock_map(t_map *map, char *av)
{
    int i = 0;
    FILE *fd;
    size_t len = 0;
    char *str = NULL;

    if ((fd = fopen(av, "r")) == NULL)
        return (1);
    while (getline(&str, &len, fd) != -1) {
        map->map[i] = strdup(str);
        map->map[i][map->largeur] = '\0';
        if (detect_error(map->map[i], map->largeur) == 1)
	        return (1);
        i = i + 1;
    }
    fclose(fd);
    return (0);
}

int	get_map(t_map *map, char *av)
{
    FILE *fd;
    char *str = NULL;
    size_t len = 0;

    map->hauteur = 0;
    if ((fd = fopen(av, "r")) == NULL)
        return (1);
    while (getline(&str, &len, fd) != -1)
        map->hauteur = map->hauteur + 1;
    map->largeur = strlen(str) - 1;
    fclose(fd);
    if ((map->map = malloc(sizeof(char *) * map->hauteur)) == NULL)
        return (1);
    if (stock_map(map, av) == 1)
        return (1);
    return (0);
}