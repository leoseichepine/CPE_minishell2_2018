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
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
        return (0);
    }
}

int add_name_end(env_t **env_copy, char *name)
{
    env_t *new = malloc(sizeof(env_t));
    env_t *tmp = *env_copy;

    if (!new)
        return (0);
    new->name = my_strdup(name);
    if (!new->name)
        return (0);
    new->value = NULL;
    new->next = NULL;
    if (*env_copy == NULL) {
        *env_copy = new;
        return (1);
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
        return (1);
    }
    return (0);
}

int add_env_name(env_t **env_copy, char *name)
{
    env_t *tmp = *env_copy;
    char *err = "setenv: Variable name must contain alphanumeric characters";

    if (!name)
        return (0);
    if (!is_alphanum_str(name))
        return (print_err(err));
    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name)) {
            free(tmp->value);
            tmp->value = NULL;
            return (1);
        }
        tmp = tmp->next;
    }
    add_name_end(env_copy, name);
    return (1);
}

int add_set_env(env_t **env_copy, char *name, char *value)
{
    env_t *tmp = *env_copy;
    char *err = "setenv: Variable name must contain alphanumeric characters";

    if (!name || !value)
        return (0);
    if (!is_alphanum_str(name))
        return (print_err(err));
    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name)) {
            free(tmp->value);
            tmp->value = my_strdup(value);
            return (1);
        }
        tmp = tmp->next;
    }
    add_node_end(env_copy, name, value);
    return (1);
}

int my_setenv(mysh_t *sh)
{
    if (sh->input->argnb > 3)
        return (print_err("Too many arguments"));
    if (sh->input->argnb == 1)
        return (my_env(sh));
    if (sh->input->argnb == 2)
        return (add_env_name(&sh->env, sh->input->arr[1]));
    if (sh->input->argnb == 3)
        return (add_set_env(&sh->env, sh->input->arr[1], sh->input->arr[2]));
    return (1);
}
