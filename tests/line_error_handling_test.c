/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(line_error_handling, simple_test, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	char *final = "Error: this line is out of range\n";
	int got = 0;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = line_error_handling(0, &board);
	cr_assert_stdout_eq_str(final);
	cr_assert_eq(got, 1, "Wrong return !\n");
}

Test(line_error_handling, valid_return, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	int got = 1000;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = line_error_handling(3, &board);
	cr_assert_eq(got, 0, "Wrong return !\n");
}
