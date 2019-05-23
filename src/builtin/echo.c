/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

static int is_in_path(char *str, env_t *env)
{
    env_t *tmp = env;

    while (tmp != NULL) {
        if (my_strcmp(str, tmp->name)) {
            write(1, tmp->value, my_strlen(tmp->value));
            return (1);
        }
        tmp = tmp->next;
    }
    my_putstr(str);
    my_putstr(": Undefined variable.");
    return (0);
}

static int choose_print_echo(char *var, env_t *env)
{
    if (var[0] != '$')
        write(1, var, my_strlen(var));
    else {
        var++;
        return (is_in_path(var, env));
    }
    return (1);
}

static int print_my_echo(mysh_t *sh)
{
    int i = 0;

    for (i = 1; sh->input->arr[i]; ++i) {
        choose_print_echo(sh->input->arr[i], sh->env);
        if (sh->input->arr[i + 1] != NULL)
            write(1, " ", 1);
        else
            write(1, "\n", 1);
    }
    return (1);
}

int my_echo(mysh_t *sh)
{
    if (sh->input->arr[1] == NULL)
        return (write(1, "\n", 1));
    else
        print_my_echo(sh);
    return (1);
}
