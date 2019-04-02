/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

char *clean_input(char *input)
{
    char *clean = NULL;
    int i = 0;

    for (int i = 0; input[i]; i++)
        if (input[i] == '\t')
            input[i] = ' ';
    for (; input[i] != '\n'; i++);
    input[i] = '\0';
    if (is_empty_str(input))
        return (NULL);
    clean = my_strdup_clean(input);
    return (clean);
}

char *my_strdup_clean(char *str)
{
    int new_len = my_strlen(str) - (count_bef(str) + count_aft(str));
    char *new = malloc(sizeof(char) * (new_len + 1));
    int i = 0;
    int j = 0;

    if (new_len <= 0)
        return (NULL);
    i = skip_spaces(str, i);
    for (; i < new_len + count_bef(str); i++) {
        new[j] = str[i];
        j++;
    }
    new[j] = '\0';
    return (new);
}

int count_aft(char *str)
{
    int res = 0;
    int i = 0;

    if (is_empty_str(str))
        return (0);
    for (; str[i + 1] != '\0'; i++);
    if (str[i] == ' ') {
        for (; str[i] == ' '; i--)
            res++;
        return (res);
    } else
        return (res);
}

int count_bef(char *str)
{
    int res = 0;

    if (str[0] == ' ') {
        for (int i = 0; str[i] == ' ' && str[i] != '\n'; i++)
            res++;
        return (res);
    }
    else
        return (0);
}

int skip_spaces(char *str, int i)
{
    for (; str[i] == ' '; i++);
    return (i);
}
