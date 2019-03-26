/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

#define CHECK (my_putstr("\nCheck\n"))
#define ABS(n) (n < 0 ? (n * -1) : n)
#define MAX(x, y) (x > y ? x : y)

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

int my_puterror(char const *str);
char *my_copycat(char *dest, char *src, int lim);
int get_char_pos(char const *str, char goal);
unsigned long long my_strlen(char const *str);
unsigned long long my_putstr(char const *str);
char *my_strdup(char *src);
int my_memcmp(void *m1, void *m2, long n);
int my_putchar(char c);
char *my_strcpy(char *dest, char *src);
long long my_getnbr(char const *str);
char **my_tablendup(char **table, int lim, int to_malloc);
unsigned long long my_put_err_nbr(signed long long int nb);
int my_putchar_err(char c);
int my_nisnum(char *str, int lim);

#endif /* MY_H_ */