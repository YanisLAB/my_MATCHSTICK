/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** tools.c
*/

#include "matchstick.h"

void free_all(map_t *map)
{
    for (int i = 0; i < map->nb_line + 2; i += 1)
        free(map->map[i]);
}

int error_check_before(char **av, int ac, map_t *map)
{
    if (ac != 3)
        return (84);
    if (!is_int(av[1]))
        return (84);
    if (!is_int(av[2]))
        return (84);
    map->nb_line = my_atoi(av[1]);
    map->nb_max = my_atoi(av[2]);
    if (map->nb_line < 1 || map->nb_line > 100)
        return (84);
    if (map->nb_max < 0)
        return (84);
    return (0);
}