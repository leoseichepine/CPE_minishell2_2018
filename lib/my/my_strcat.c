/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int new_len = my_strlen(dest) + my_strlen(src);
    int i = 0;
    char *new_str = malloc(sizeof(char) * (new_len + 1));

    if (!new_str)
        return (NULL);
    for (int j = 0; dest[j] != '\0'; j++) {
        new_str[i] = dest[j];
        i++;
    }
    for (int j = 0; src[j] != '\0'; j++) {
        new_str[i] = src[j];
        i++;
    }
    new_str[new_len] = '\0';
    return (new_str);
}
