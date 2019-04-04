/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) - 1;
    int demilen = (len + 1) / 2;
    char tmp;

    while ( i < demilen ) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i++;
        len--;
    }
    return (str);
}
