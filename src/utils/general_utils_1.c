/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

void free_arr(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    return ;
}

int is_empty_str(char *str)
{
    if (!str || *str == '\n')
        return (1);
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ' && str[i] != '\t')
            return (0);
    return (1);
}
