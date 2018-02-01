/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/
#include "my.h"

void place_sticks(char **map, int length)
{
	int i = 0;
	int start = 1;
	int stop = length - 1;

	for (; map[i + 2]; i++);
	for (; i >= 0; i--) {
		for (int j = start; j < stop; j++)
			map[i][j] = '|';
		start++;
		stop--;
	}
}

void my_box_creator(int i, char **map, int lines, int length)
{
	for (int j = 0; j < length; j++) {
		if (i == 0 || i == lines + 1 || j == 0 || j == length - 1)
			map[i][j] = '*';
		else
			map[i][j] = ' ';
	}
	map[i][length] = 0;
}

char **my_map_creator(int lines)
{
	char **map = malloc(sizeof(char *) * (lines + 3));
	int length = 3 + 2 * (lines - 1);

	if (!map)
		return (NULL);
	map[lines + 2] = NULL;
	for (int i = 0; i < lines + 2; i++) {
		map[i] = malloc(sizeof(char) * (length + 1));
		if (!map[i])
			return (NULL);
		my_box_creator(i, map, lines, length);
	}
	place_sticks(map, length);
	return (map);
}

map_t init_board(char **str)
{
	map_t my_map;

	my_map.lines = my_getnbr(str[1]);
	my_map.max_take_out = my_getnbr(str[2]);
	if (my_map.lines <= 1 || my_map.lines >= 100
		|| my_map.max_take_out <= 0) {
		my_map.lines = -1;
		return (my_map);
	}
	my_map.map = my_map_creator(my_map.lines);
	if (!my_map.map) {
		my_map.lines = -1;
		return (my_map);
	}
	my_map.remaining_matches = sum_n_odd_numbers(my_map.lines);
	return (my_map);
}
