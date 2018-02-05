/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/
#include "my.h"

int seek_last_line(map_t *board)
{
	int line = 1;

	for (; number_on_line(board->map, line) <= 1; line++);
	return (line);
}

int *check_map_status(map_t *board)
{
	int *status = malloc(sizeof(int) * 3);

	if (!status)
		return (NULL);
	status[0] = 0;
	status[1] = 0;
	status[2] = 0;
	for (int i = 1; board->map[i + 1]; i++) {
		if (number_on_line(board->map, i) == 1)
			status[0]++;
		else if (number_on_line(board->map, i) > 1)
			status[1]++;
		else if (number_on_line(board->map, i) < 1)
			status[2]++;
	}
	return (status);
}
