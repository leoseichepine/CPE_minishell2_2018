/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int count_word(char *str)
{
    int res = 0;
    int state = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
            state = 0;
        else if (state == 0) {
            state = 1;
            res++;
        }
    }
    return (res);
}

int get_word_len(char *str, int nb)
{
    int res = 0;
    int i = 0;

    i = skip_spaces(str, i);
    for (; str[i] != '\0' && nb > 0; i++)
        if (str[i] == ' ') {
            i = skip_spaces(str, i);
            nb--;
        }
    if (i != 0 && str[i - 1] != ' ')
        i--;
    for (; str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != '\t'; i++)
        res++;
    return (res);
}

char *get_next_word(char *str, int nb, int len)
{
    int i = 0;
    char *word = malloc(sizeof(char) * (len + 1));

    if (!word)
        return (NULL);
    i = skip_spaces(str, i);
    for (; str[i] != '\0' && nb > 0; i++)
        if (str[i] == ' ') {
            i = skip_spaces(str, i);
            nb--;
        }
    if (i != 0 && str[i - 1] != ' ')
        i--;
    for (int j = 0; str[i] != '\0' && str[i] != ' '; i++, j++)
        word[j] = str[i];
    word[len] = '\0';
    return (word);
}
