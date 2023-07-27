#include "shell.h"

/**
 * execute_cmd - execute a command
 * @argv: the command and its arguments
 */
void execute_cmd(char **argv)
{
        char *command = NULL;
        char *actual_command = NULL;
        char *error_msg = NULL;
        pid_t pid;
        int status;

        pid = fork();
        if (pid == 0)
        {
                if (argv)
                {
                        command = argv[0];
                        actual_command = handle_path(command);
                        if (actual_command != NULL)
                        {
                                if (execve(actual_command, argv, NULL) == -1)
                                        perror("execve");
                                free(actual_command);
                        }
                        else
                        {
                                write(1, command, strlen(command));
                                error_msg = ": command not found";
                                write(1, error_msg, strlen(error_msg));
                                putchar('\n');
                        }
                }
                exit(0);
        }
        else
                wait(&status);
}
