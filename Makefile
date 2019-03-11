##
## EPITECH PROJECT, 2018
## makefile csfml
## File description:
## makefile csfml
##

SRC			=	src/main.c \
				src/my_defender.c \
				src/setup/setup.c \
				src/setup/setup_objects.c \
				src/setup/setup_buttons.c \
				src/setup/setup_menu.c \
				src/music.c

NAME		=	mysh

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Iinclude

INCLUDE		=	-I./include/my.h

LIBFLAGS	=	-Llib/my -lmy

all			:	$(NAME)

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
