/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int my_putstr(char const *str)
{
    int res = 0;

    if (!str)
        return (84);
    for (int i = 0; str[i] != '\0'; i++, res++)
        my_putchar(str[i]);
    return (res);
}
