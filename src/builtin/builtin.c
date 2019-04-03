/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int my_env(mysh_t *sh)
{
    env_t *tmp = sh->env;

    if (sh->env->name == NULL)
        return (84);
    while (tmp != NULL) {
        my_printf("%s=%s\n", tmp->name, tmp->value);
        tmp = tmp->next;
    }
    return (0);
}

int my_exit(mysh_t *sh)
{
    sh->info->state = 0;
    return (0);
}
