/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_compute_factorial_rec(int nb)
{
    long fac = nb;

    if(nb < 0)
        return (0);
    if(nb == 0)
        return (1);
    if(nb != 1)
        fac = (my_compute_factorial_rec (nb - 1) * nb);
    return (fac);
}
