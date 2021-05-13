/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** game2.c
*/

#include "matchstick.h"

void print_map(map_t *map)
{
    for (int i = 0; i < map->nb_line + 2; i += 1) {
        my_putstr(map->map[i]);
        my_putchar('\n');
    }
}

bool game_end(map_t *map)
{
    for (int i = 0; i <= map->nb_line; i += 1) {
        for (int n = 0; map->map[i][n]; n += 1) {
            if (map->map[i][n] == '|')
                return (false);
        }
    }
    return (true);
}

int line_check(map_t *map, int line)
{
    int n = 0;
    for (int i = 0; map->map[line][i]; i += 1) {
        if (map->map[line][i] == '|')
            n += 1;
    }
    return (n);
}

void remove_stick(map_t *map, int matches, int line)
{
    int n = matches;
    for (int i = my_strlen(map->map[line]); n > 0; i -= 1) {
        if (map->map[line][i] == '|') {
            map->map[line][i] = ' ';
            n -= 1;
        }
    }
}

int check_matches2(int tmp, map_t *map)
{
    int tmp2 = 0;
    for (int i = 0; map->map[map->line][i]; i += 1) {
        if (map->map[map->line][i] == '|') {
            tmp2 += 1;
        }
    }
    if (tmp2 >= tmp) {
        return (0);
    } else {
        return (1);
    }
}