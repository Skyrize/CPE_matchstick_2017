/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(check_and_print_lost_sentence, player_lose, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	char *final = "You lost, too bad...\n";
	int got = 0;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	board.remaining_matches = 0;
	got = check_and_print_lost_sentence(0, &board);
	cr_assert_stdout_eq_str(final, "Invalid sentence !\n");
	cr_assert_eq(got, 2, "Wrong return !\n");
}

Test(check_and_print_lost_sentence, AI_lose, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	char *final = "I lost... snif... but I'll get you next time!!\n";
	int got = 0;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	board.remaining_matches = 0;
	got = check_and_print_lost_sentence(1, &board);
	cr_assert_stdout_eq_str(final, "Invalid sentence !\n");
	cr_assert_eq(got, 1, "Wrong return !\n");
}

Test(check_and_print_lost_sentence, not_lose_yet, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	int got = 0;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = check_and_print_lost_sentence(0, &board);
	cr_assert_eq(got, 0, "Wrong return !\n");
}
