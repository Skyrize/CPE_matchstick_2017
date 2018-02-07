/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(my_box_creator, simple_creator_test)
{
	char **map = malloc(sizeof(char *) * 4);
	int lines = 2;
	int length = 5;

	for (int i = 0; i < lines + 2; i++) {
		map[i] = malloc(sizeof(char) * (length + 1));
		my_box_creator(i, map, lines, length);
	}
	cr_assert_str_eq(map[0], "*****", "fnct changed first line!\n");
	cr_assert_str_eq(map[1], "*   *", "Wrong 2nd line!\n");
	cr_assert_str_eq(map[2], "*   *", "Wrong 3rd line!\n");
	cr_assert_str_eq(map[3], "*****", "fnct changed last line!\n");
}

Test(my_box_creator, simple_creator2_test)
{
	char **map = malloc(sizeof(char *) * 5);
	int lines = 3;
	int length = 7;

	for (int i = 0; i < lines + 2; i++) {
		map[i] = malloc(sizeof(char) * (length + 1));
		my_box_creator(i, map, lines, length);
	}
	cr_assert_str_eq(map[0], "*******", "fnct changed first line!\n");
	cr_assert_str_eq(map[1], "*     *", "Wrong 2nd line!\n");
	cr_assert_str_eq(map[2], "*     *", "Wrong 3rd line!\n");
	cr_assert_str_eq(map[3], "*     *", "Wrong 4th line!\n");
	cr_assert_str_eq(map[4], "*******", "fnct changed last line!\n");
}
