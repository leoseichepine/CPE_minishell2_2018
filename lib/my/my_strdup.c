/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include<stdlib.h>
#include "my.h"

char *my_strdup(char *src)
{
    char *new;

    if (!src)
        return (NULL);
    new = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (int i = 0; src[i]; i++)
        new[i] = src[i];
    new[my_strlen(src)] = '\0';
    return (new);
}
