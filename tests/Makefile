##
## EPITECH PROJECT, 2018
## minishell1
## File description
## Makefile
##

CC	=	gcc

WFLAGS		=	-Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

CFLAGS		=	-I../include -L../lib/my/ -lmy --coverage -lcriterion

RM	=	rm -rf

SRCTEST	=	place_sticks_test.c	\
		my_box_creator_test.c	\
		my_map_creator_test.c	\
		init_board_test.c	\
		seek_a_line_test.c	\
		number_on_line_test.c	\
		compute_ai_turn_test.c	\
		matches_error_handling_test.c	\
		line_error_handling_test.c	\
		check_and_print_lost_sentence_test.c	\
		remove_matches_from_line_and_print_test.c	\
		count_matches_on_line_test.c	\
		../sources/my_initializer.c	\
		../sources/my_displayer.c	\
		../sources/matches_tools.c	\
		../sources/artificial_intelligence_functions.c	\
		../sources/player_turn_functions.c

OBJTEST	=	$(SRCTEST:.c=.o)

NAMETEST	=	unit-tests

all:	tests_run

tests_run:	$(OBJTEST)
	$(CC) -o $(NAMETEST) $(OBJTEST) $(CFLAGS) $(WFLAGS)

clean:
	$(RM) $(OBJTEST)
	$(RM) ../sources/*.gcda
	$(RM) ../sources/*.gcno
	$(RM) ./*.gcda
	$(RM) ./*.gcno

fclean: clean
	$(RM) $(NAMETEST)

re:	fclean all
