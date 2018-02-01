/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/
#include "my.h"

int matches_error_handling(int line, int nb_matches, map_t *board)
{
	int real_nb_matches = count_matches_on_line(line, board);

	if (nb_matches <= 0) {
		my_printf("Error: you have to remove at least on match\n");
		return (1);
	}
	if (nb_matches > board->max_take_out) {
		my_printf("Error: you cannot remove more ");
		my_printf("than %d matches per turn\n", board->max_take_out);
		return (1);
	}
	if (nb_matches > real_nb_matches) {
		my_printf("Error: not enough matches on this line\n");
		return (1);
	}
	return (0);
}

int line_error_handling(int line, map_t *board)
{
	if (line > board->lines || line <= 0) {
		my_printf("Error: this line is out of range\n");
		return (1);
	}
	return (0);
}

int game_loop(map_t *board)
{
	int error_no = -1;

	while (1) {
		if (error_no == -1)
			my_printf("\nYour turn:\n");
		error_no = compute_player_turn(board);
		if (error_no == 84)
			return (84);
		else if (error_no == 1)
			continue;
		if (board->remaining_matches == 0) {
			my_printf("You lost, too bad...\n");
			return (2);
		}
		compute_ai_turn(board);
		if (board->remaining_matches == 0) {
			my_printf("I lost... snif... but I'll get you next");
			my_printf(" time!!\n");
			return (1);
		}
		error_no = -1;
	}
	return (0);
}
