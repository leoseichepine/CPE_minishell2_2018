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

char **load_env_arr(mysh_t *sh)
{
    char **env_arr = NULL;
    char *env_line = NULL;
    int i = 0;
    env_t *tmp = sh->env;

    env_arr = malloc(sizeof(char *) * (my_env_size(sh) + 1));
    if (!env_arr)
        return (NULL);
    while (tmp != NULL) {
        env_line = my_strdup(my_strcat(tmp->name, "="));
        env_line = my_strdup(my_strcat(env_line, tmp->value));
        env_arr[i] = my_strdup(env_line);
        if (!env_arr[i])
            return (NULL);
        free(env_line);
        i++;
        tmp = tmp->next;
    }
    env_arr[my_env_size(sh)] = NULL;
    return (env_arr);
}
