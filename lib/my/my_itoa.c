/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_itoa(int nb)
{
    int size = find_int_len(nb);
    char *nbc = NULL;
    int i = 0;

    nbc = malloc(sizeof(char) * size + 1);
    if (!nbc)
        return (NULL);
    for (; i < size; i++) {
        nbc[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    nbc[i] = '\0';
    my_revstr(nbc);
    return (nbc);
}
