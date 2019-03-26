/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int my_sh(mysh_t *sh)
{
    while (sh->info->state) {
        signal(SIGINT, &signal_c);
        my_printf("$>");
    }
    return (0);
}

int check_args(int ac, char **av)
{
    if (ac > 1 || *av == NULL)
        return (84);
    return (0);
}

int main (int ac, char **av, char **envp)
{
    mysh_t *sh = NULL;
    int err = 0;

    if (check_args(ac, av) == 84)
        return (84);
    sh = init_struct(envp);
    if (!sh || !sh->info)
        return (84);
    err = my_sh(sh);
    free_struct(sh);
    return (err);
}
