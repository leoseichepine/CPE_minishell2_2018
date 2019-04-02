##
## EPITECH PROJECT, 2018
## makefile csfml
## File description:
## makefile csfml
##

SRC			=	src/main.c\
				src/setup.c\
				src/env/env.c\
				src/utils/str_tok.c\
				src/utils/signal.c\
				src/utils/error.c\
				src/input/parsing_input.c\
				src/input/cleaning_input.c\
				src/utils/general_utils_1.c\
				src/input/input.c

NAME		=	mysh

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Iinclude

INCLUDE		=	-I./include/my.h

LIBFLAGS	=	-Llib/my -lmy

all			:	$(NAME) clean

debug		:
				gcc -o  $(NAME) $(SRC) $(LIBFLAGS) $(CFLAGS) -g

$(NAME)		:	$(OBJ)
				gcc -g -o $(NAME) $(OBJ) $(LIBFLAGS) $(INCLUDE) $(CFLAGS)

clean		:
				rm -f $(OBJ)

fclean		:	clean
				rm -f $(NAME)
				rm -f vgcore*

re			:	fclean all

.PHONY		:	all clean fclean re
