/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int input_to_arr(mysh_t *sh, char *input)
{
    char *clean = clean_input(input);

    if (!clean)
        return (0);
    sh->input->argnb = count_word(clean);
    if (sh->input->argnb == 0)
        return (0);
    sh->input->arr = malloc(sizeof(char *) * (sh->input->argnb + 1));
    if (!sh->input->arr)
        return (0);
    for (int i = 0; i < sh->input->argnb; i++) {
        sh->input->arr[i] = get_next_word(clean, i, get_word_len(clean, i));
        if (!sh->input->arr[i])
            return (0);
    }
    sh->input->arr[sh->input->argnb] = NULL;
    free(clean);
    return (1);
}

int get_input(mysh_t *sh)
{
    char *s = NULL;
    size_t len = 0;
    int read = 0;

    sh->input->argnb = 0;
    sh->input->arr = NULL;
    read = getline(&s, &len, stdin);
    if (error_input(sh, read) == 84) {
        free(s);
        return (0);
    }
    input_to_arr(sh, s);
    free(s);
    return (1);
}
