#include "shell.h"

/**
 * handle_cmd - handle the commande execution
 * @argv: pointer to an array of command line arguments
 * Return: void
 */

void handle_cmd(char **argv)
{
        char *command = NULL, *actual_command = NULL;
        pid_t pid;
        int status;

        pid = fork();
        if (pid == 0)
        {
                 if (argv)
                 {
                         command = argv[0];
                         actual_command = handle_path(command);
                         if (execve(actual_command, argv, NULL) == -1)
                         {
                                 perror("Error:");
                         }
                 }
         }
         else
                 wait(&status);
}
