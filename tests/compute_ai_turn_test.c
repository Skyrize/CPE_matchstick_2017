/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** (enter)
*/

#include "my.h"

Test(compute_ai_turn, simple_test, .init = cr_redirect_stdout)
{
	char **str = malloc(sizeof(char *) * 3);
	map_t board;
	char *norme1 = "\nAI's turn...\nAI removed 1 match(es) from line 1\n";
	char *norme2 = "*******\n*     *\n* ||| *\n*|||||*\n*******\n";
	char *final = my_strcat(norme1, norme2);

	str[0] = my_strdup("useless");
	str[1] = my_strdup("3");
	str[2] = my_strdup("100");
	board = init_board(str);
	compute_ai_turn(&board);
	cr_assert_stdout_eq_str(final);
}
