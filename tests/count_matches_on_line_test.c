/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(count_matches_on_line, test_line_1)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	int got = 84;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = count_matches_on_line(1, &board);
	cr_assert_eq(got, 1, "Expected to find 1 matches but got %d\n", got);
}

Test(count_matches_on_line, test_line_2)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	int got = 84;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = count_matches_on_line(2, &board);
	cr_assert_eq(got, 3, "Expected to find 3 matches but got %d\n", got);
}

Test(count_matches_on_line, test_line_3)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	int got = 84;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = count_matches_on_line(3, &board);
	cr_assert_eq(got, 5, "Expected to find 5 matches but got %d\n", got);
}

Test(count_matches_on_line, test_line_0)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	int got = 84;

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	got = count_matches_on_line(0, &board);
	cr_assert_eq(got, 0, "Expected to find 0 match but got %d\n", got);
}
