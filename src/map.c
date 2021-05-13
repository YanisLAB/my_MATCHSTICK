/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** map.c
*/

#include "matchstick.h"

void alloc_map(map_t *map)
{
    map->map = malloc(sizeof(char *) * map->nb_line + 2);
    for (int i = 0; i < map->nb_line + 2; i += 1)
        map->map[i] = malloc(sizeof(char) * ((map->nb_line * 2) - 1 + 3));
}

void fill_map(map_t *map, int *m, int *k, int i)
{
    int n = 1;
    map->map[i][0] = '*';
    for (int h = 0; h < *k / 2; h += 1, n += 1)
        map->map[i][n] = ' ';
    for (int h = 0; h < *m; h += 1, n += 1)
        map->map[i][n] = '|';
    for (int h = 0; h < *k / 2; h += 1, n += 1)
        map->map[i][n] = ' ';
    map->map[i][n] = '*';
    map->map[i][n + 1] = '\0';
}

int gen_map(map_t *map)
{
    int m = 0;
    int k = 0;
    char *star;

    alloc_map(map);
    star = malloc(sizeof(char) * ((map->nb_line * 2) + 1));
    for (int i = 0; i < (map->nb_line * 2) + 1; i += 1)
        star[i] = '*';
    map->map[0] = my_strdup(star);
    map->map[map->nb_line + 1] = my_strdup(star);
    m = map->nb_line * 2 - 1;
    for (int i = map->nb_line; i > 0; i -= 1) {
        fill_map(map, &m, &k, i);
        m -= 2;
        k += 2;
    }
    return (0);
}