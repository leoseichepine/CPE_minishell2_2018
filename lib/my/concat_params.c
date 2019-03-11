/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** __DESCRIPTION__
*/

#include<stdlib.h>
#include "my.h"

char *concat_params(int argc, char **argv)
{
    int i = 0;
    char *str = NULL;
    int len = 0;

    for(int i = 0; i < argc; i++) {
        len += my_strlen(argv[i]);
        i++;
        len++;
    }
    str = malloc(sizeof(char) * (len + 1));
    *str = '\0';
    for (i = 0; i < argc; i++) {
        my_strcat(str, argv[i]);
        my_strcat(str, "\n");
    }
    return (str);
}
