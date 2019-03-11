/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0
    int j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != src[nb]) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
