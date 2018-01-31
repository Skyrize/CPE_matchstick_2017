/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** my.h
*/
#include "my.h"

int	main(int ac, char **av)
{
	map_t board;

	if (ac != 3)
		return (84);
	board = init_board(av);
	if (board.lines == -1)
		return (84);
	for (int i = 0; board.map[i]; i++)
		my_printf("%s\n", board.map[i]);
	game_loop(&board);
	for (int i = 0; board.map[i]; i++)
		free(board.map[i]);
	free(board.map);
	return (0);
}
