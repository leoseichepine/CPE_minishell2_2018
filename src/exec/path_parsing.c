/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

char *get_path(env_t **env_copy)
{
    char *path_not_parsed = NULL;
    env_t *tmp = *env_copy;

    while (tmp != NULL) {
        if (my_strcmp("PATH", tmp->name)) {
            path_not_parsed = my_strdup(tmp->value);
            if (!path_not_parsed)
                return (NULL);
            return (path_not_parsed);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

int get_path_size(char *path)
{
    int size = 0;

    if (!path)
        return (0);
    for (int i = 0; path[i] != '\0'; i++)
        if (path[i] == ':')
            size++;
    return (size + 1);
}

int get_path_len(char *path, int number)
{
    int res = 0;
    int i = 0;

    while (path[i] != '\0' && number > 0) {
        if (path[i] == ':')
            number--;
        i++;
    }
    if (i != 0 && path[i - 1] != ':')
        i--;
    for (; path[i] != '\0' && path[i] != '\n' && path[i] != ':'; i++)
        res++;
    return (res);
}

char **get_real_path(env_t **env_copy)
{
    char *path = get_path(env_copy);
    char **real_path = NULL;
    int path_len = 0;
    int i = 0;

    if (!path || get_path_size(path) <= 0)
        return (NULL);
    real_path = malloc(sizeof(char *) * (get_path_size(path) + 1));
    if (!real_path)
        return (NULL);
    for (; i < get_path_size(path); i++) {
        path_len = get_path_len(path, i);
        real_path[i] = get_word(path, ':', i, path_len);
        if (!real_path[i])
            return (NULL);
    }
    real_path[i] = NULL;
    free(path);
    return (real_path);
}
