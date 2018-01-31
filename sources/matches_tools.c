/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/
#include "my.h"

int look_who_won(map_t *board)
{
	(void)board;
	return (0);
}

int count_matches_on_line(int line, map_t *board)
{
	int count = 0;

	for (int i = 0; board->map[line][i]; i++) {
		if (board->map[line][i] == '|')
			count++;
	}
	return (count);
}
