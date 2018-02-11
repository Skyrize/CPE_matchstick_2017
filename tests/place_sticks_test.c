/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(place_stick, test_simple)
{
	char **map = malloc(sizeof(char *) * 5);
	int length = 5;

	map[0] = my_strdup("*****");
	map[1] = my_strdup("*   *");
	map[2] = my_strdup("*   *");
	map[3] = my_strdup("*****");
	map[4] = NULL;
	place_sticks(map, length);
	cr_assert_str_eq(map[0], "*****", "fnct changed first line!\n");
	cr_assert_str_eq(map[1], "* | *", "Wrong 2nd line!\n");
	cr_assert_str_eq(map[2], "*|||*", "Wrong 3rd line!\n");
	cr_assert_str_eq(map[3], "*****", "fnct changed last line!\n");
}

Test(place_stick, test_simple_2)
{
	char **map = malloc(sizeof(char *) * 6);
	int length = 7;

	map[0] = my_strdup("*******");
	map[1] = my_strdup("*     *");
	map[2] = my_strdup("*     *");
	map[3] = my_strdup("*     *");
	map[4] = my_strdup("*******");
	map[5] = NULL;
	place_sticks(map, length);
	cr_assert_str_eq(map[0], "*******", "fnct changed first line!\n");
	cr_assert_str_eq(map[1], "*  |  *", "Wrong 2nd line!\n");
	cr_assert_str_eq(map[2], "* ||| *", "Wrong 3rd line!\n");
	cr_assert_str_eq(map[3], "*|||||*", "Wrong 4th line!\n");
	cr_assert_str_eq(map[4], "*******", "fnct changed last line!\n");
}
