/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

char *my_str_before_tok(char *str, char tok)
{
    char *new_str;
    int new_len = 0;

    for (; str[new_len] != tok; new_len++);
    new_str = malloc(sizeof(char) * (new_len + 1));
    if (!new_str)
        return (NULL);
    for (int i = 0; str[i] != tok; i++)
        new_str[i] = str[i];
    new_str[new_len] = '\0';
    return (new_str);
}

char *my_str_after_tok(char *str, char tok)
{
    char *new_str;
    int i = 0;
    int new_len = 0;
    int j = 0;

    for (i = 0; str[i] != tok; i++);
    for (; str[i] != '\0'; i++)
        new_len++;
    new_str = malloc(sizeof(char) * (new_len + 1));
    if (!new_str)
        return (NULL);
    for (; str[j - 1] != tok; j++);
    for (int i = 0; i < new_len; i++) {
        new_str[i] = str[j];
        j++;
    }
    new_str[new_len] = '\0';
    return (new_str);
}
