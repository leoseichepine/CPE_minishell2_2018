##
## EPITECH PROJECT, 2018
## Makefile_Lib
## File description:
## Makefile Convertir .c en .o Créer une Lib Supprimer fichiers inutiles
##

SRC 		=	concat_params.c\
				convert_base.c\
				dec_to_hexa_lc.c\
				dec_to_hexa_uc.c\
				find_int_len.c\
				funcmpf_1.c\
				funcmpf_2.c\
				funcmpf_3.c\
				itab_to_i.c\
				my_atoi.c\
				my_compute_factorial_it.c\
				my_compute_factorial_rec.c\
				my_compute_power_it.c\
				my_isneg.c\
				my_itoa.c\
				my_printf.c\
				my_put_unsigned_int.c\
				my_putchar.c\
				my_putnbr.c\
				my_putstr.c\
				my_putstroct.c\
				my_revstr.c\
				my_show_word_array.c\
				my_strcat.c\
				my_strcpy.c\
				my_strdup.c\
				my_strlen.c\
				my_strcat.c\
				my_strncpy.c\
				my_swap.c

OBJ 		=	$(SRC:.c=.o)

NAME_LIB	=	libmy.a

NAME_H		=	my.h

NAME_MAKE 	=	Makefile

all			:	$(NAME_LIB) clean

$(NAME_LIB)	:	$(OBJ)
				ar rc $(NAME_LIB) $(OBJ)
				cp $(NAME_H) ../../include

clean		:
				rm -f $(OBJ)
				rm -f *.gcno *.gcda *~ *#

fclean		:	clean
				rm -f $(NAME_LIB)

re			:	fclean all
