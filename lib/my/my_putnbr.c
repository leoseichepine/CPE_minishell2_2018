/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_putnbr(int nbr)
{
    int nbrlen = find_int_len(nbr);

    if (nbr < 0) {
        my_putchar('-');
        my_putchar(nbr * (-1) + '0');
    }
    else if (nbr < 10) {
        my_putchar(nbr + '0');
    }
    else {
        my_putnbr(nbr / 10);
        my_putchar((nbr % 10) + '0');
    }
    return (nbrlen);
}
