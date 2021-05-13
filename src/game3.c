/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** game3.c
*/

#include "matchstick.h"

void print_ia(map_t *map, int matches, int line)
{
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    remove_stick(map, matches, line);
}

int check_matchesp2(int tmp_matches, map_t *map)
{
    if (tmp_matches == 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (-1);
    }
    if (tmp_matches > map->nb_max) {
        write(1, "Error: you cannot remove more than ", 35);
        my_put_nbr(map->nb_max);
        write(2, " matches per turn\n", 18);
        return (-1);
    }
    if (check_matches2(tmp_matches, map) == 1) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (-1);
    }
    return (0);
}