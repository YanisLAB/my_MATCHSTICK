/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** matchstick.h
*/

#ifndef __MATCHSTICK_H__
#define __MATCHSTICK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

typedef struct map {
    char **map;
    int nb_line;
    int nb_max;
    int line;
    int matches;
}map_t;

//~~~~~{Game}~~~~~
int game(map_t *map);
bool game_end(map_t *map);
void print_map(map_t *map);
int line_check(map_t *map, int line);
int check_matches2(int tmp, map_t *map);
int check_matchesp2(int tmp_matches, map_t *map);
void print_ia(map_t *map, int matches, int line);
void remove_stick(map_t *map, int matches, int line);

//~~~~~{Map}~~~~~
int gen_map(map_t *map);

//~~~~~{Error}~~~~~
int error_check_before(char **av, int ac, map_t *map);

//~~~~~{Tools}~~~~~
bool is_int(char *av);
int my_put_nbr(int nb);
void my_putchar(char c);
char *my_strdup(char *str);
int my_atoi(char const *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

#endif