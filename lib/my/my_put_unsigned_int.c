/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_put_unsigned_int(unsigned int nb)
{
    int nbrlen = find_int_len(nb);

    if (nb < 0 || nb > 4290000000) {
        return (84);
    } else if (nb < 10) {
        my_putchar(nb + '0');
    } else {
        my_putnbr(nb / 10);
        my_putchar((nb % 10) + '0');
    }
    return (nbrlen);
}
