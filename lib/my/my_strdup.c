/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include<stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *str2;
    int len = my_strlen(src);

    str2 = malloc(sizeof(char) * len);
    while (i < len) {
        str2[i] = src[i];
        i++;
    }
    str2[i] == '\0';
    return (str2);
}
