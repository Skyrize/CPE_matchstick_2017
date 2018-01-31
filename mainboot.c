/*
** EPITECH PROJECT, 2017
** baudonnel
** File description:
** (enter)
*/
#include "my.h"

void printf_game_board(void)
{
	char *map = "*********\n*   |   *\n*  |||  *\n* ||||| *\n*|||||||*\n*********\n";
	my_printf("%s", map);
}

int error_handling(int *i, int line, int nb_matches, char *map)
{
	int line_lector = 1;
	int real_number_matches = 0;

	for (; line_lector != line && map[*i]; (*i)++) {
		if (map[*i] == '\n')
			line_lector++;
	}
	if (line_lector != line || line > 4) {
		my_printf("Error: This line is out of range\n");
		return (84);
	}
	for (int j = *i; map[j] != '\n'; j++) {
		if (map[j] == '|')
			real_number_matches++;
	}
	if (real_number_matches < nb_matches) {
		my_printf("Error: not enough matches on this line\n");
		return (84);
	}
	return (0);
}

void print_updated_board_game(int line, int nb_matches)
{
	char *map = my_strdup("*********\n*   |   *\n*  |||  *\n* ||||| *\n*|||||||*\n*********\n");
	int i = 0;

	for (; map[i] != '\n'; i++);
	i++;
	if (error_handling(&i, line, nb_matches, map) != 0)
		exit (84);
	for (; map[i] != '\n' && nb_matches != 0; i++) {
		if (map[i] == '|') {
			map[i] = ' ';
			nb_matches--;
		}
	}
	my_printf("\n%s", map);
	free(map);
}

int seek_a_line(char *map)
{
	int line = 1;

	for (int i = 10; map[i] != '|'; i++) {
		if (map[i] == '\n')
			line++;
	}
	return (line);
}

int number_on_line(char *map, int line)
{
	int matches = 0;

	for (int i = line * 10; map[i] != '\n'; i++) {
		if (map[i] == '|') {
			matches++;
		}
	}
	return (matches);
}

void read_player_move_and_print_updated_board_game(void)
{
	char *player_input;
	char *map = my_strdup("*********\n*   |   *\n*  |||  *\n* ||||| *\n*|||||||*\n*********\n");
	int i = 10;
	int test = 10;
	int line = 1;
	int matches = 1;
	int total_matches = 16;
	int ai_line = 1;
	int ai_matches = 1;

	while (1) {
		my_printf("Line: ");
		test = 10;
		player_input = my_get_next_line(0);
		line = my_getnbr(player_input);
		if (error_handling(&test, line, 0, map) != 0) {
			free(player_input);
			continue;
		}
		my_printf("Matches: ");
		player_input = my_get_next_line(0);
		matches = my_getnbr(player_input);
		if (matches <= 0) {
			my_printf("Error: you have to remove at least one match\n");
			free(player_input);
			continue;
		}
		test = 10;
		if (error_handling(&test, line, matches, map) != 0) {
			free(player_input);
			continue;
		}
		error_handling(&i, line, matches, map);
		for (; map[i + 1] != '\n'; i++);
		total_matches -= matches;
		my_printf("Player removed %d match(es) from line %d\n", matches, line);
		for (; map[i] != '\n' && matches != 0; i--) {
			if (map[i] == '|') {
				map[i] = ' ';
				matches--;
			}
		}
		total_matches -= matches;
		my_printf("\n%s", map);
		my_printf("AI's turn...\n");
		ai_line = seek_a_line(map);
		ai_matches = (int)random() % number_on_line(map, ai_line) + 1;
		total_matches -= ai_matches;
		i = 10 * ai_line;
		my_printf("AI removed %d match(es) from line %d\n", ai_matches, ai_line);
		for (; map[i + 1] != '\n'; i++);
		for (; map[i] != '\n' && ai_matches != 0; i--) {
			if (map[i] == '|') {
				map[i] = ' ';
				ai_matches--;
			}
		}
		my_printf("\n%s", map);
		i = 10;
		if (total_matches <= 0)
			break;
	}
	free(map);
}

int main(int ac, char **av)
{/*
	int line;
	int nb_to_remove;

	if (ac != 3) {
		my_printf("enter the line and the number of matches to remove.\n");
		return (84);
	}
	line = my_getnbr(av[1]);
	nb_to_remove = my_getnbr(av[2]);
	printf_game_board();
	print_updated_board_game(line, nb_to_remove);*/
	read_player_move_and_print_updated_board_game();
	return (0);
}
