/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int is_alphanum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int is_alphanum_str(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!is_alphanum(str[i]))
            return (0);
    return (1);
}

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2) || !str1 || !str2)
        return (0);
    for (int i = 0; str1[i]; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}

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
