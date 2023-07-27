#include "shell.h"

/**
 * execute_cmd - execute a command
 * @argv: the command and its arguments
 */
void execute_cmd(char **argv)
{
    char *command = argv[0];
    char *actual_command = handle_path(command);     pid_t pid;
    int status;
char *error_msg = NULL;
    if (actual_command != NULL)
    {
        pid = fork();
        if (pid == 0)
        {
            if (execve(actual_command, argv, NULL) == -1)
                perror("execve");
            free(actual_command);
            exit(EXIT_FAILURE); 
        }
        else if (pid > 0)
        {
            wait(&status);
        }
        else
        {
            perror("fork");
        }
    }
    else
    {
        write(1, command, strlen(command));
        error_msg = ": command not found";
        write(1, error_msg, strlen(error_msg));
        putchar('\n');
    }
}

