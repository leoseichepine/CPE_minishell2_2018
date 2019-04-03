/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int count_cmd_nb(char *input)
{
    int res = 1;
    char key[2] = {'|', ';'};

    for (int i = 0; key[i]; i++)
        if (input[0] == key[i] && input[my_strlen(input)] == key[i])
            return (0);
    for (int i = 0; input[i]; i++) {
        for (int j = 0; key[j]; j++)
            if (input[i] == key[j])
                res++;
    }
    return (res);
}

char *get_next_cmd(char *input, int nb)
{
    return (NULL);
}

char **input_to_arr(mysh_t *sh, char *input)
{
    char *clean = clean_input(input);
    char **arr = NULL;

    if (!clean)
        return (NULL);
    sh->input->cmd_nb = count_cmd_nb(clean);
    printf("cmd nb = %i\n", sh->input->cmd_nb);
    if (sh->input->cmd_nb == 0)
        return (NULL);
    arr = malloc(sizeof(char *) * (sh->input->cmd_nb + 1));
    if (!arr)
        return (0);
    arr[sh->input->cmd_nb] = NULL;
    free(clean);
    return (NULL);
}

int get_input(mysh_t *sh)
{
    char *s = NULL;
    char **arr = NULL;
    size_t len = 0;
    int read = 0;

    read = getline(&s, &len, stdin);
    if (error_input(sh, read) == 84) {
        free(s);
        return (0);
    }
    input_to_arr(sh, s);
    free(s);
    return (1);
}
