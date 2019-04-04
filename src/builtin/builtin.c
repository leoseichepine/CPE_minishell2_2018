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
        return (0);
    while (tmp != NULL) {
        my_printf("%s=%s\n", tmp->name, tmp->value);
        tmp = tmp->next;
    }
    return (1);
}

int my_exit(mysh_t *sh)
{
    my_putstr("exit\n");
    sh->info->state = 0;
    return (1);
}
