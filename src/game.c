/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** game.c
*/

#include "matchstick.h"

int check_matches(char *matches, map_t *map)
{
    int tmp_matches = 0;
    if (!is_int(matches)) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (-1);
    } else {
        tmp_matches = my_atoi(matches);
        if (check_matchesp2(tmp_matches, map) == -1)
            return (-1);
    }
    map->matches = tmp_matches;
    return (0);
}

int check_line(char *line, map_t *map)
{
    int tmp_line = 0;
    if (!is_int(line)) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (-1);
    } else {
        tmp_line = my_atoi(line);
        if (tmp_line < 1 || tmp_line > map->nb_line) {
            write(1, "Error: this line is out of range\n", 33);
            return (-1);
        }
    }
    map->line = tmp_line;
    return (0);
}

int player(map_t *map)
{
    size_t n = 0;
    char *line;

    my_putstr("Line: ");
    if (getline(&line, &n, stdin) == -1) return (-1);
    line[my_strlen(line) - 1] = '\0';
    if (check_line(line, map) == -1)
        return (player(map));
    my_putstr("Matches: ");
    if (getline(&line, &n, stdin) == -1) return (-1);
    line[my_strlen(line) - 1] = '\0';
    if (check_matches(line, map) == -1)
        return (player(map));
    my_putstr("Player removed ");
    my_put_nbr(map->matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(map->line);
    my_putchar('\n');
    remove_stick(map, map->matches, map->line);
    return (0);
}

void ia(map_t *map)
{
    srand(time(NULL));
    int line = (rand() % map->nb_line) * 1;
    int matches = (rand() % map->nb_max) * 1;
    int m_max = 0;
    while (1) {
        m_max = line_check(map, line);
        if (m_max == 0)
            line = (rand() % (map->nb_line + 1)) * 1;
        else
            break;
    }
    while (1) {
        if (matches % 2 == 0) {
            matches = (rand() % map->nb_max) * 1;
        } else if (matches <= m_max)
            break;
        else
            matches = (rand() % map->nb_max) * 1;
    }
    print_ia(map, matches, line);
}

int game(map_t *map)
{
    print_map(map);
    my_putchar('\n');
    while (1) {
        my_putstr("Your turn: \n");
        if (player(map) == -1) return (3);
        print_map(map);
        if (game_end(map) == true) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        my_putchar('\n');
        my_putstr("AI's turn...\n");
        ia(map);
        print_map(map);
        if (game_end(map) == true) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
        my_putchar('\n');
    }
}