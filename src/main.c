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
    clean = my_strdup_clean(input);
    return (clean);
}

int input_to_tab(mysh_t *sh, char *input)
{
    char *clean = NULL;

    sh->input->argnb = count_word(input);
    printf("argnb = %i\n", sh->input->argnb);
    clean = clean_input(input);
    free(clean);
    return (0);
}

int my_sh(mysh_t *sh)
{
    size_t len = 0;
    char *s = NULL;
    int read = 0;

    while (sh->info->state) {
        signal(SIGINT, &signal_c);
        my_printf("$>");
        s = NULL;
        read = getline(&s, &len, stdin);
        if (error_input(sh, read) == 84) {
            free(s);
            return (0);
        }
        // input_to_tab(sh, s);
        free(s);
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
