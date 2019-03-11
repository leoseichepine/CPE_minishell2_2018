/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_atoi(char *str)
{
    int len = my_strlen(str);
    int newnb = 0;

    while (*str != '\0') {
        newnb = newnb * 10 + (*str - '0');
        str++;
    }
    return (newnb);
}
