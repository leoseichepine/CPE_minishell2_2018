/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include <stdio.h>
#include "my.h"

int convert_base(int nb, int base)
{
    int tabtmp[1000];
    int newnb = 0;
    int i = 0;

    while (nb > 0) {
        tabtmp[i] = nb % base;
        nb = nb / base;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        my_putnbr(tabtmp[j]);
    return (i);
}
