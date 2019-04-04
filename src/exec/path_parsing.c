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

char *get_next_path(char *path, int path_len, int number)
{
    char *word = NULL;
    int i = 0;
    int j = 0;

    word = malloc(sizeof(char) * (path_len + 1));
    while (path[i] != '\0' && number > 0) {
        if (path[i] == ':')
            number--;
        i++;
    }
    if (i != 0 && path[i - 1] != ':')
        i--;
    for (; path[i] != '\0' && path[i] != '\n' && path[i] != ':'; i++) {
        word[j] = path[i];
        j++;
    }
    return (word);
}

char **get_real_path(env_t **env_copy)
{
    char *path_not_parsed = get_path(env_copy);
    int path_size = get_path_size(path_not_parsed);
    char **real_path = malloc(sizeof(char *) * (path_size + 1));
    int path_len = 0;

    if (!path_not_parsed || !path_size)
        return (NULL);
    for (int i = 0; i < path_size; i++) {
        path_len = get_path_len(path_not_parsed, i);
        real_path[i] = get_next_path(path_not_parsed, path_len, i);
        real_path[i][path_len] = '\0';
    }
    real_path[path_size] = NULL;
    free(path_not_parsed);
    return (real_path);
}
