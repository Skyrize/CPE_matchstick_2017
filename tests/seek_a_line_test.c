/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(seek_a_line, test_seek_first_line)
{
	char **map = malloc(sizeof(char *) * 6);
	int got = 0;

	map[0] = my_strdup("*******");
	map[1] = my_strdup("*  |  *");
	map[2] = my_strdup("* ||| *");
	map[3] = my_strdup("*|||||*");
	map[4] = my_strdup("*******");
	map[5] = NULL;
	got = seek_a_line(map);
	cr_assert_eq(got, 1, "Skiped or crash before reaching the first line!");
}

Test(seek_a_line, test_seek_last_line)
{
	char **map = malloc(sizeof(char *) * 6);
	int got = 0;

	map[0] = my_strdup("*******");
	map[1] = my_strdup("*     *");
	map[2] = my_strdup("*     *");
	map[3] = my_strdup("*|    *");
	map[4] = my_strdup("*******");
	map[5] = NULL;
	got = seek_a_line(map);
	cr_assert_eq(got, 3, "Skiped or crash before reaching the last line!");
}

Test(seek_a_line, test_seek_empty)
{
	char **map = malloc(sizeof(char *) * 6);
	int got = 100;

	map[0] = my_strdup("*******");
	map[1] = my_strdup("*     *");
	map[2] = my_strdup("*     *");
	map[3] = my_strdup("*     *");
	map[4] = my_strdup("*******");
	map[5] = NULL;
	got = seek_a_line(map);
	cr_assert_eq(got, 0, "Invalid read with no matchsticks !");
}
