/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != src[n]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] != '\0';
    return (dest);
}
