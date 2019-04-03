/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2) || !str1 || !str2)
        return (0);
    for (int i = 0; str1[i]; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}

// int process_input(mysh_t *sh)
// {
//     char *key[6] = {"exit", "cd", "env", "setenv", "unsetenv", NULL};
//     builtin_t builtin[5] = {&my_exit, &my_exit, &my_exit, &my_exit, &my_exit};
//
//     if (sh->input->argnb == 0 || is_empty_str(sh->input->arr[0]))
//         return (0);
//     for (int i = 0; key[i]; i++) {
//         if (my_strcmp(sh->input->arr[0], key[i]))
//             return (builtin[i](sh));
//     }
//     return (0);
// }

int my_sh(mysh_t *sh)
{
    while (sh->info->state) {
        signal(SIGINT, &signal_c);
        my_printf("$>");
        if (!get_input(sh))
            return (0);
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
