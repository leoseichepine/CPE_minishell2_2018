/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include <stdio.h>
#include "my.h"

int itab_to_i(int arr[], int len)
{
    int nb = 0;
    int i = 0;

    for (i = 0; i < len; i++) {
        nb = nb * 10 + arr[i];
    }
    return (nb);
}
