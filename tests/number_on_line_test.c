/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(number_on_line, test_simple)
{
	char **map = malloc(sizeof(char *) * 6);
	int got = 0;

	map[0] = my_strdup("*******");
	map[1] = my_strdup("*  |  *");
	map[2] = my_strdup("* ||| *");
	map[3] = my_strdup("*|||||*");
	map[4] = my_strdup("*******");
	map[5] = NULL;
	got = number_on_line(map, 0);
	cr_assert_eq(got, 0, "Expected 0 for map[0] but got %d!\n", got);
	got = number_on_line(map, 1);
	cr_assert_eq(got, 1, "Expected 1 for map[1] but got %d!\n", got);
	got = number_on_line(map, 2);
	cr_assert_eq(got, 3, "Expected 3 for map[2] but got %d!\n", got);
	got = number_on_line(map, 3);
	cr_assert_eq(got, 5, "Expected 5 for map[3] but got %d!\n", got);
}
