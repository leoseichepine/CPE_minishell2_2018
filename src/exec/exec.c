/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int exec_command(mysh_t *sh, char *command_path)
{
    char **env_arr = load_env_arr(sh);
    int status = 0;
    pid_t pid = fork();

    if (pid == -1) {
        my_printf("Fork failed\n");
        return (0);
    } else if (pid == 0) {
        if (execve(command_path, sh->input->arr, env_arr) == -1) {
            my_printf("Exec Failed\n");
            return (0);
        }
        return (1);
    } else {
        if (wait(&status) < 0)
            return (0);
    }
    free_arr(env_arr);
    return (1);
}

int my_exec(mysh_t *sh)
{
    char *my_path = my_strcat("/", sh->input->arr[0]);
    char **real_path = get_real_path(&sh->env);
    char *command_path = NULL;
    int ex = 0;

    for (int i = 0; real_path[i] != NULL; i++) {
        command_path = my_strcat(real_path[i], my_path);
        if (access(command_path, F_OK) == 0) {
            ex = exec_command(sh, command_path);
            free(real_path);
            free(command_path);
            free(my_path);
            return (ex);
        }
    }
    my_printf("%s: Command not found.\n", sh->input->arr[0]);
    free_arr(real_path);
    free(command_path);
    free(my_path);
    return (1);
}
