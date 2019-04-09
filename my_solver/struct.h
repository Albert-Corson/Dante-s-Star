/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct	s_map
{
  int		hauteur;
  int		largeur;
  char		**map;
} t_map;

void print_map(t_map *map);
int	detect_error(char *line, int largeur);
int	stock_map(t_map *map, char *av);
int	get_map(t_map *map, char *av);
#endif /* !STRUCT_H_ */
