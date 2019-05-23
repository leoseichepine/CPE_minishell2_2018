/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** __DESCRIPTION__
*/

#include "minishell2.h"
#include "header.h"
#include "my.h"

int exit_child_process(int stat)
{
    int signals[] = {SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGTRAP, SIGBUS, SIGFPE,
    SIGKILL, SIGSEGV, SIGTERM, SIGABRT, 0};
    char *text[11] = {"Hangup", "", "Quit", "Illegal instruction",
    "Trace/BTP trap", "Bus error", "Floating exception", "Killed",
    "Segmentation fault", "Terminated", "Aborted"};
    int sig = WTERMSIG(stat);

    for (int i = 0; signals[i]; i++)
        if (signals[i] == sig)
            my_putstr(text[i]);
    if (WCOREDUMP(stat))
        my_putstr(" (core dumped)\n");
    return (0);
}

int exec_command(mysh_t *sh, char *command_path)
{
    char **env_arr = load_env_arr(sh);
    int status = 0;
    pid_t pid = fork();

    if (pid == -1) {
        free_arr(env_arr);
        print_err("Fork error\n");
    } else if (pid == 0) {
        if (execve(command_path, sh->input->arr, env_arr) == -1) {
            my_printf("%s: Command not found.\n", command_path);
            return (0);
        }
        return (1);
    } else {
        wait(&status);
        exit_child_process(status);
        free_arr(env_arr);
        return (1);
    }
    return (1);
}

int exec_cmd_path(mysh_t *sh)
{
    char *my_path = my_strcat("/", sh->input->arr[0]);
    char **real_path = get_real_path(&sh->env);
    char *command_path = NULL;
    int ex = 0;

    for (int i = 0; real_path[i]; i++) {
        command_path = my_strcat(real_path[i], my_path);
        if (access(command_path, F_OK | X_OK) == 0) {
            free_arr(real_path);
            free(my_path);
            ex = exec_command(sh, command_path);
            free(command_path);
            return (ex);
        }
        free(command_path);
    }
    my_printf("%s: Command not found.\n", sh->input->arr[0]);
    free_arr(real_path);
    free(my_path);
    return (1);
}

int is_already_path(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '/')
            return (1);
    return (0);
}

int my_redirect_exec(mysh_t *sh)
{
    if (is_already_path(sh->input->arr[0]))
        return (exec_command(sh, sh->input->arr[0]));
    else
        return (exec_cmd_path(sh));
    return (0);
}
