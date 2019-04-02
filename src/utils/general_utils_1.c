/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int is_empty_str(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            return (0);
    return (1);
}
