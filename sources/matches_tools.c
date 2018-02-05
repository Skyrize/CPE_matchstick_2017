/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/
#include "my.h"

void remove_matches_from_line_and_print(map_t *board, int matches, int line)
{
	for (int i = 2 + 2 * (board->lines - 1); i > 0 && matches != 0; i--) {
		if (board->map[line][i] == '|') {
			board->map[line][i] = ' ';
			matches--;
		}
	}
	for (int i = 0; board->map[i]; i++)
		my_printf("%s\n", board->map[i]);
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
