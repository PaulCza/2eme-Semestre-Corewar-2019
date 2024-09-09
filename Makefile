##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME		=	asm/asm
UTNAME	=	unit_tests

SRC 		=	lib/my/fonction_printf/hexa.c \
				lib/my/fonction_printf/my_conv_oct.c \
				lib/my/fonction_printf/my_convhexa.c \
				lib/my/fonction_printf/my_printf.c \
				lib/my/fonction_printf/my_put_nbr.c \
				lib/my/fonction_printf/my_putchar.c \
				lib/my/fonction_printf/my_putstr_detect.c \
				lib/my/fonction_printf/my_putstr.c \
				lib/my/fonction_printf/number_case.c \
				lib/my/fonction_str_to_word/str_to_word.c \
				lib/my/list_fonction/list_fonction.c \
				lib/my/list_fonction/list_fonction2.c \
				lib/my/disp_stdarg.c \
				lib/my/corewar/assembleur/init_the_wall.c \
				lib/my/corewar/assembleur/create_the_file.c \
				lib/my/corewar/assembleur/analyse_fonct.c \
				lib/my/corewar/assembleur/function_bib.c \
				lib/my/corewar/assembleur/little_end_to_big.c \
				lib/my/corewar/assembleur/arg_funct.c \
				lib/my/corewar/op.c \
				lib/my/my_getnbr.c \
				lib/my/my_revstr.c \
				lib/my/my_strcpy.c \
				lib/my/my_strlen.c \
				lib/my/my_to_binary.c \
				lib/my/my_transformnbr.c \
				lib/my/parcour_2.c \
				lib/my/parcour.c \
				lib/my/same_char.c \
				lib/my/sum_stdarg.c \
				main.c \
				in_search_of_and_write.c \
				lib/my/corewar/assembleur/error/input.c \
				lib/my/corewar/assembleur/error/start.c \
				lib/my/corewar/assembleur/error/error_checker.c \
				lib/my/corewar/assembleur/error/name_com_finder.c \
				lib/my/corewar/assembleur/error/label.c \
				lib/my/corewar/assembleur/error/label_2.c

UTSRC	=	$(addprefix lib/my/,	\
			fonction_printf/hexa.c	\
			fonction_printf/my_conv_oct.c \
			fonction_printf/my_convhexa.c \
			fonction_printf/my_printf.c \
			fonction_printf/my_put_nbr.c \
			fonction_printf/my_putchar.c \
			fonction_printf/my_putstr_detect.c \
			fonction_printf/my_putstr.c \
			fonction_printf/number_case.c \
			fonction_str_to_word/str_to_word.c \
			list_fonction/list_fonction.c \
			list_fonction/list_fonction2.c \
			disp_stdarg.c \
			corewar/assembleur/init_the_wall.c \
			corewar/assembleur/create_the_file.c \
			corewar/assembleur/analyse_fonct.c \
			corewar/assembleur/function_bib.c \
			corewar/assembleur/little_end_to_big.c \
			corewar/assembleur/arg_funct.c \
			corewar/op.c \
			my_getnbr.c \
			my_revstr.c \
			my_strcpy.c \
			my_strlen.c \
			my_to_binary.c \
			my_transformnbr.c \
			parcour_2.c \
			parcour.c \
			same_char.c \
			sum_stdarg.c) \
			in_search_of_and_write.c \
			$(addprefix tests/,	\
			test_lib.c			\
			test_printf.c		\
			test_lists.c		\
			test_arg_func.c		\
			)

#############################################################################
CC			?=	gcc

OBJ			=	$(SRC:.c=.o)

CPPFLAGS	=	-I./include/

CFLAGS		=	-W -Wall -Wextra

LDFLAGS		=
LIBFLAGS	=
#############################################################################

all:	$(NAME)

$(NAME): $(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

debug: CFLAGS += -g3
debug:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(CPPFLAGS)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)

re:		fclean all

tests_run:	LDFLAGS += -lcriterion --coverage
tests_run:
		@$(CC) -o $(UTNAME) $(UTSRC) $(CPPFLAGS) $(LDFLAGS)
		./unit_tests
		@echo -e "$(GREEN)gcovr --exclude tests/$(END)" && gcovr --exclude tests/
		@echo -e "$(GREEN)gcovr --branches --exclude tests/$(END)" && gcovr --branches --exclude tests/
		@echo -e "$(GREEN)* * * * * * * * * * * * * * TESTS COMPLETED * * * * * * * * * * * * * *$(END)"

###################    COLOR CODE    #################################################################################
GREEN		=	\e[32m
END			=	\e[0m
######################################################################################################################

.PHONY:	re fclean clean tests_run debug
