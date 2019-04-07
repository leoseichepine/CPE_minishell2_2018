/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int my_env_size(mysh_t *sh)
{
    int res = 0;
    env_t *tmp = sh->env;

    while (tmp != NULL) {
        res++;
        tmp = tmp->next;
    }
    return (res);
}

char *my_strcat_triple(char *str1, char *str2, char *str3)
{
    int len = 0;
    char *new = NULL;
    int i = 0;

    if (!str1 || !str2 || !str3)
        return (NULL);
    len = my_strlen(str1) + my_strlen(str2) + my_strlen(str3);
    new = malloc(sizeof(char) * (len + 1));
    if (!new)
        return (NULL);
    for (int j = 0; j < my_strlen(str1); i++, j++)
        new[i] = str1[j];
    for (int j = 0; j < my_strlen(str2); i++, j++)
        new[i] = str2[j];
    for (int j = 0; j < my_strlen(str3); i++, j++)
        new[i] = str3[j];
    new[i] = '\0';
    return (new);
}

char **load_env_arr(mysh_t *sh)
{
    char **env_arr = NULL;
    int i = 0;
    env_t *tmp = sh->env;

    env_arr = malloc(sizeof(char *) * (my_env_size(sh) + 1));
    if (!env_arr)
        return (NULL);
    while (tmp != NULL) {
        env_arr[i] = my_strcat_triple(tmp->name, "=", tmp->value);
        if (!env_arr[i])
            return (NULL);
        i++;
        tmp = tmp->next;
    }
    env_arr[i] = NULL;
    return (env_arr);
}
