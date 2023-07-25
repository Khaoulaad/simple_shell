#include "shell.h"

/**
 * main - entry point
 * @ac: number of command line arguments
 * @argv: pointer to an array of command line arguments
 * Return: integer
 */

int main(int ac, char **argv)
{
        char *prompt = "#shell$ ";
        char *lineptr = NULL;
        size_t n = 0;
        ssize_t number_of_char;
        pid_t pid;
        int status;
        int interactive = isatty(STDIN_FILENO);
        int isfirst = 1;
	size_t len 
        (void)ac;

        while (1)
        {
                if (interactive || isfirst)
                        printf("%s", prompt);
                isfirst = 0;

                number_of_char = getline(&lineptr, &n, stdin);
                if (number_of_char == -1)
                {
			free(lineptr);
                        break;
                }
		len = strlen(lineptr);
		if (len > 0 && lineptr[len - 1] == '\n')
			lineptr[len - 1] = '\0';

                pid = fork();
                if (pid == 0)
                {
                        if (execve(lineptr, argv, NULL) == -1)
                                perror("execve");
                }
                else
                        wait(&status);
        }
        return (0);
}
