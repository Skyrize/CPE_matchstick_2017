/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(init_board, simple_test)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	cr_assert_str_eq(board.map[0], "*******", "fnct changed first line!\n");
	cr_assert_str_eq(board.map[1], "*  |  *", "Wrong 2nd line!\n");
	cr_assert_str_eq(board.map[2], "* ||| *", "Wrong 3rd line!\n");
	cr_assert_str_eq(board.map[3], "*|||||*", "Wrong 4th line!\n");
	cr_assert_str_eq(board.map[4], "*******", "fnct changed last line!\n");
	cr_assert_null(board.map[5], "Last index isn't null !!\n");
	cr_assert_eq(board.lines, 3, "Number of lines isn't good!\n");
	cr_assert_eq(board.max_take_out, 100, "Max takeout isn't good!\n");
	cr_assert_eq(board.remaining_matches, 9, "invalid total matches!\n");
}
