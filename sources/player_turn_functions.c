/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/
#include "my.h"

int get_line(int *line, map_t *board, char *player_input)
{
	my_printf("Line: ");
	player_input = my_get_next_line(0);
	if (!player_input)
		return (84);
	if (my_str_isnum(player_input) != 0) {
		my_printf("Error: invalid input (positive number expected)\n");
		return (1);
	}
	*line = my_getnbr(player_input);
	return (line_error_handling(*line, board));
}

int get_matches(int line, int *matches, map_t *board, char *player_input)
{
	my_printf("Matches: ");
	player_input = my_get_next_line(0);
	if (!player_input)
		return (84);
	if (my_str_isnum(player_input) != 0) {
		my_printf("Error: invalid input (positive number expected)\n");
		return (1);
	}
	*matches = my_getnbr(player_input);
	return (matches_error_handling(line, *matches, board));
}

int compute_player_turn(map_t *board, char *player_input)
{
	int line = 0;
	int matches = 0;
	int error_no = get_line(&line, board, player_input);

	if (error_no != 0)
		return (error_no);
	error_no = get_matches(line, &matches, board, player_input);
	if (error_no != 0)
		return (error_no);
	board->remaining_matches -= matches;
	my_printf("Player removed %d match(es) from line %d\n", matches, line);
	for (int i = 2 + 2 * (board->lines - 1); i > 0 && matches != 0; i--) {
		if (board->map[line][i] == '|') {
			board->map[line][i] = ' ';
			matches--;
		}
	}
	for (int i = 0; board->map[i]; i++)
		my_printf("%s\n", board->map[i]);
	return (0);
}
