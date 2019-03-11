/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int find_int_len(int nb)
{
    if(nb >= 1000000000)
        return (10);
    if(nb >= 100000000)
        return (9);
    if(nb >= 10000000)
        return (8);
    if(nb >= 1000000)
        return (7);
    if(nb >= 100000)
        return (6);
    if(nb >= 10000)
        return (5);
    if(nb >= 1000)
        return (4);
    if(nb >= 100)
        return (3);
    if(nb >= 10)
        return (2);
    return (1);
}
