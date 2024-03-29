/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int process_input(mysh_t *sh)
{
    char *key[7] = {"exit", "cd", "env", "setenv", "unsetenv", "echo", NULL};
    builtin_t builtin[6] =
    {&my_exit, &my_cd, &my_env, &my_setenv, &my_unsetenv, &my_echo};

    if (!sh->input->arr || !sh->input->argnb)
        return (0);
    for (int i = 0; key[i]; i++)
        if (my_strcmp(sh->input->arr[0], key[i]))
            return (builtin[i](sh));
    if (!my_redirect_exec(sh))
        return (0);
    return (1);
}

int my_sh(mysh_t *sh)
{
    sh->info->state = 1;
    while (sh->info->state) {
        sh->info->tty = isatty(0);
        signal(SIGINT, &signal_c);
        if (sh->info->tty)
            my_putstr("\033[0;31m$>\033[0m");
        if (!get_input(sh))
            return (0);
        process_input(sh);
        if (sh->input->arr)
            free_arr(sh->input->arr);
    }
    return (0);
}

int check_args(int ac, char **av)
{
    if (ac > 1 || *av == NULL)
        return (84);
    return (0);
}

int main(int ac, char **av, char **envp)
{
    mysh_t *sh = NULL;
    int err = 0;

    if (check_args(ac, av) == 84)
        return (84);
    sh = init_struct(envp);
    if (!sh || !sh->info || !sh->input)
        return (84);
    err = my_sh(sh);
    free_struct(sh);
    return (err);
}
