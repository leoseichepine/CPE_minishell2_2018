/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int add_node_end(env_t **env_copy, char *name, char *value)
{
    env_t *new = malloc(sizeof(env_t));
    env_t *tmp = *env_copy;

    if (!new)
        return (84);
    new->name = my_strdup(name);
    new->value = my_strdup(value);
    new->next = NULL;
    if (*env_copy == NULL) {
        *env_copy = new;
        return (0);
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
        return (0);
    }
}

int add_name_end(env_t **env_copy, char *name)
{
    env_t *new = malloc(sizeof(env_t));
    env_t *tmp = *env_copy;

    if (!new)
        return (84);
    new->name = my_strdup(name);
    new->value = NULL;
    new->next = NULL;
    if (*env_copy == NULL) {
        *env_copy = new;
        return (0);
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
        return (0);
    }
    return (0);
}

int add_env_name(env_t **env_copy, char *name)
{
    env_t *tmp = *env_copy;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name)) {
            tmp->value = NULL;
            return (0);
        }
        tmp = tmp->next;
    }
    add_name_end(env_copy, name);
    return (0);
}

int add_set_env(env_t **env_copy, char *name, char *value)
{
    env_t *tmp = *env_copy;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name)) {
            tmp->value = my_strdup(value);
            return (0);
        }
        tmp = tmp->next;
    }
    add_node_end(env_copy, name, value);
    return (0);
}

int my_setenv(mysh_t *sh)
{
    if (sh->input->argnb == 1)
        return (my_env(sh));
    if (sh->input->argnb == 2)
        return (add_env_name(&sh->env, sh->input->arr[1]));
    if (sh->input->argnb == 3)
        return (add_set_env(&sh->env,
        sh->input->arr[1], sh->input->arr[2]));
    if (sh->input->argnb > 3) {
        my_printf("Too many arguments\n");
        return (84);
    }
    return (0);
}
