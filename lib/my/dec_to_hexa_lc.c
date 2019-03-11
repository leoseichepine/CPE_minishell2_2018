/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int convert_dec_to_hexa_lc(unsigned long nb)
{
    char hexadecinum[10000];
    int i = 0;
    int tmp = 0;

    while (nb != 0) {
        tmp = nb % 16;
        if (tmp < 10) {
            hexadecinum[i] = tmp + 48;
            i++;
        } else {
            hexadecinum[i] = tmp + 55 + 32;
            i++;
        }
        nb = nb / 16;
    }
    for (int j = i - 1; j >= 0; j--)
        my_putchar(hexadecinum[j]);
    return (i);
}
