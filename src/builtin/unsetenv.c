/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int delete_first_node(env_t **list, char *name)
{
    env_t *prev;

    if (*list != NULL && my_strcmp((*list)->name, name)) {
        prev = *list;
        *list = (*list)->next;
        free(prev->name);
        free(prev->value);
        free(prev);
        return (1);
    }
    return (0);
}

int delete_env_node(env_t **list, char *name)
{
    env_t *tmp = *list;
    env_t *prev = NULL;

    if (delete_first_node(list, name))
        return (0);
    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name)) {
            if (prev != NULL)
                prev->next = tmp->next;
            free(tmp->name);
            free(tmp->value);
            free(tmp);
            return (0);
        }
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return (84);
    return (0);
}

int my_unsetenv(mysh_t *sh)
{
    env_t *tmp = sh->env;

    if (sh->input->argnb <= 1) {
        my_putstr("Too few arguments\n");
        return (84);
    }
    while (tmp != NULL) {
        for (int i = 1; i < sh->input->argnb; i++) {
            if (my_strcmp(tmp->name, sh->input->arr[i])) {
                return (delete_env_node(&sh->env, sh->input->arr[i]));
            }
        }
        tmp = tmp->next;
    }
    return (0);
}
