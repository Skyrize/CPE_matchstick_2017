##
## EPITECH PROJECT, 2018
## minishell1
## File description:
## Makefile
##

CC		=	gcc

WFLAGS		=	-Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

CFLAGS		=	-I./include -L./lib/my/ -lmy -g3

COV	=	--coverage -lcriterion

RM	=	rm -rf

SRC	=	main.c	\
		sources/my_initializer.c	\
		sources/my_displayer.c	\
		sources/matches_tools.c	\
		sources/artificial_intelligence_functions.c	\
		sources/player_turn_functions.c

SRCTEST	=	tests/place_sticks_test.c	\
		tests/my_box_creator_test.c	\
		tests/my_map_creator_test.c	\
		tests/init_board_test.c	\
		tests/seek_a_line_test.c	\
		tests/number_on_line_test.c	\
		tests/compute_ai_turn_test.c	\
		tests/matches_error_handling_test.c	\
		tests/line_error_handling_test.c	\
		tests/check_and_print_lost_sentence_test.c	\
		tests/remove_matches_from_line_and_print_test.c	\
		sources/my_initializer.c	\
		sources/my_displayer.c	\
		sources/matches_tools.c	\
		sources/artificial_intelligence_functions.c	\
		sources/player_turn_functions.c

OBJS	=	$(SRC:.c=.o)

OBJTEST	=	$(SRCTEST:.c=.o)

NAME	=	matchstick

NAME2	=	unit-tests

all: prepare_lib $(NAME)


tests_run:	prepare_lib $(OBJTEST)
	$(CC) -o $(NAME2) $(OBJTEST) $(CFLAGS) $(WFLAGS) $(COV)
	./unit-tests


prepare_lib:
	make -C lib/my


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(WFLAGS) $(CFLAGS)


clean:
	make clean -C lib/my
	$(RM) $(OBJS)
	$(RM) $(OBJTEST)
	$(RM) */*.gcda
	$(RM) */*.gcno
	$(RM) ./*.gcda
	$(RM) ./*.gcno


fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME2)


re: fclean all
