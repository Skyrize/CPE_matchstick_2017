/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(my_map_creator, test_simple)
{
	char **map = my_map_creator(2);

	cr_assert_str_eq(map[0], "*****", "fnct changed first line!\n");
	cr_assert_str_eq(map[1], "* | *", "Wrong 2nd line!\n");
	cr_assert_str_eq(map[2], "*|||*", "Wrong 3rd line!\n");
	cr_assert_str_eq(map[3], "*****", "fnct changed last line!\n");
	cr_assert_null(map[4], "Last index isn't null !!\n");
}

Test(my_map_creator, test_simple_2)
{
	char **map = my_map_creator(3);

	cr_assert_str_eq(map[0], "*******", "fnct changed first line!\n");
	cr_assert_str_eq(map[1], "*  |  *", "Wrong 2nd line!\n");
	cr_assert_str_eq(map[2], "* ||| *", "Wrong 3rd line!\n");
	cr_assert_str_eq(map[3], "*|||||*", "Wrong 4th line!\n");
	cr_assert_str_eq(map[4], "*******", "fnct changed last line!\n");
	cr_assert_null(map[5], "Last index isn't null !!\n");
}

Test(my_map_creator, test_simple_3)
{
	char **map = my_map_creator(4);

	cr_assert_str_eq(map[0], "*********", "fnct changed first line!\n");
	cr_assert_str_eq(map[1], "*   |   *", "Wrong 2nd line!\n");
	cr_assert_str_eq(map[2], "*  |||  *", "Wrong 3rd line!\n");
	cr_assert_str_eq(map[3], "* ||||| *", "Wrong 4th line!\n");
	cr_assert_str_eq(map[4], "*|||||||*", "Wrong 5th line!\n");
	cr_assert_str_eq(map[5], "*********", "fnct changed last line!\n");
	cr_assert_null(map[6], "Last index isn't null !!\n");
}
