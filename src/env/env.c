/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int free_env(env_t **liste)
{
    env_t *tmp = *liste;
    env_t *next;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp->name);
        free(tmp->value);
        free(tmp);
        tmp = next;
    }
    *liste = NULL;
    return (0);
}

int add_env_elem(env_t **head, char *name, char *value)
{
    env_t *new = malloc(sizeof(env_t));
    env_t *tmp = (*head);

    if (!new)
        return (84);
    new->name = my_strdup(name);
    new->value = my_strdup(value);
    new->next = NULL;
    if ((*head) == NULL) {
        (*head) = new;
        return (0);
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (0);
}

/*
ENV IS NULL :
-HOSTTYPE=x86_64-linux
-VENDOR=unknown
-OSTYPE=linux
-MACHTYPE=x86_64
-SHLVL=1
-PWD=/home/lseichepine/delivery/PSU/PSU_minishell2_2018
-LOGNAME=lseichepine
-USER=lseichepine
-GROUP=lseichepine
-HOST=localhost.localdomain
*/

int copy_env(env_t **list, char **envp)
{
    char *name = NULL;
    char *value = NULL;

    if (*envp == NULL) {
        printf("ENV IS NULL\n");
        return (0);
    }
    for (int i = 0; envp[i] != NULL; i++) {
        name = my_str_before_tok(envp[i], '=');
        value = my_str_after_tok(envp[i], '=');
        add_env_elem(list, name, value);
        free(name);
        free(value);
    }
    return (0);
}
