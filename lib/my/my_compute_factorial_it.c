/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_compute_factorial_it(int nb)
{
    long fac = 0;

    fac = 1;
    if (nb == 0)
        return (1);
    if (nb < 0)
        return (0);
    for (int i = 1; i <= nb; i++) {
        fac = fac * i;
    }
    return (fac);
}
