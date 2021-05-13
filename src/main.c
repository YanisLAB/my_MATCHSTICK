/*
** EPITECH PROJECT, 2021
** matchsticks
** File description:
** main.c
*/

#include "matchstick.h"

bool is_int(char *av)
{
    for (int i = 0; av[i]; i += 1) {
        if ((av[i] < '0' || av[i] > '9') && av[i] != '-')
            return (false);
    }
    return (true);
}

int main(int ac, char **av)
{
    map_t map;
    int ret = 0;

    if (error_check_before(av, ac, &map) == 84)
        return (84);
    if (gen_map(&map) == 84)
        return (84);
    ret = game(&map);
    if (ret == 84)
        return (84);
    if (ret == 3)
        return (0);
    return (ret);
}