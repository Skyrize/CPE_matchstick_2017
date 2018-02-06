/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

int seek_a_line(char **map)
{
	int line = 1;
	int j = 0;

	for (int i = 0; map[j][i] != '|'; i++) {
		if (map[i] == 0) {
			j++;
			i = -1;
		}
	}
	return (j);
}

int number_on_line(char **map, int line)
{
	int matches = 0;

	for (int i = 0; map[line][i]; i++) {
		if (map[line][i] == '|') {
			matches++;
		}
	}
	return (matches);
}

int compute_ai_turn(map_t *board)
{
	int line = seek_a_line(board->map);
	int nb_on_line = number_on_line(board->map, line);
	int matches = random() % nb_on_line + 1;

	my_printf("\nAI's turn..\n");
	if (matches > board->max_take_out)
		matches = matches % board->max_take_out + 1;
	board->remaining_matches -= matches;
	my_printf("AI removed %d match(es) from line %d\n", matches, line);
	remove_matches_from_line_and_print(board, matches, line);
	return (0);
}
