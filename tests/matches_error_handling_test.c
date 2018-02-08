/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(matches_error_handling, invalid_matches_remove, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	char *final = "Error: you have to remove at least one match\n";
	int got = 0;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = matches_error_handling(1, 0, &board);
	cr_assert_stdout_eq_str(final, "Invalid sentence !\n");
	cr_assert_eq(got, 1, "Wrong return !\n");
}

Test(matches_error_handling, too_many_matches, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	char *norme1 = "Error: you cannot remove more ";
	char *norme2 = "than 100 matches per turn\n";
	char *final = my_strcat(norme1, norme2);
	int got = 0;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = matches_error_handling(1, 150, &board);
	cr_assert_stdout_eq_str(final, "Invalid sentence !\n");
	cr_assert_eq(got, 1, "Wrong return !\n");
}

Test(matches_error_handling, not_enough_matches, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	char *final = "Error: not enough matches on this line\n";
	int got = 0;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = matches_error_handling(2, 4, &board);
	cr_assert_stdout_eq_str(final, "Invalid sentence !\n");
	cr_assert_eq(got, 1, "Wrong return !\n");
}

Test(matches_error_handling, valid_return, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	int got = 100;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = matches_error_handling(3, 3, &board);
	cr_assert_eq(got, 0, "Wrong return !\n");
}
