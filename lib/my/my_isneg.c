/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar ('N');
        my_putchar ('\n');
    } else {
        my_putchar ('P');
        my_putchar ('\n');
    }
    return(0);
}
