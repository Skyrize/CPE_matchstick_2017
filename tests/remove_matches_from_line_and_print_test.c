/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(remove_matches_from_line_and_print, test_remove_1)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	remove_matches_from_line_and_print(&board, 2, 2);
	cr_assert_str_eq(board.map[0], "*******", "fnct changed first line!\n");
	cr_assert_str_eq(board.map[1], "*  |  *", "Wrong 2nd line!\n");
	cr_assert_str_eq(board.map[2], "* |   *", "Wrong 3rd line!\n");
	cr_assert_str_eq(board.map[3], "*|||||*", "Wrong 4th line!\n");
	cr_assert_str_eq(board.map[4], "*******", "fnct changed last line!\n");
	cr_assert_null(board.map[5], "Last index isn't null !!\n");
}

Test(remove_matches_from_line_and_print, test_print, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	char *final = "*******\n*  |  *\n* |   *\n*|||||*\n*******\n";
	map_t board;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	remove_matches_from_line_and_print(&board, 2, 2);
	cr_assert_stdout_eq_str(final);
}
