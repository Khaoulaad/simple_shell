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
        char *lineptr = NULL, *lineptr_copy = NULL;
        size_t n = 0;
        ssize_t number_of_char;
        const char *delim = " \n";
        int num_tokens = 0;
        char *token;
        int i;
        pid_t pid;
        int status;
        int interactive = isatty(STDIN_FILENO);
        int isfirst = 1;
        (void)ac;

        while (1)
        {
                if (interactive || isfirst)
                        printf("%s", prompt);
                isfirst = 0;

                number_of_char = getline(&lineptr, &n, stdin);
                if (number_of_char == -1)
                {
                        return (-1);
                }
                lineptr_copy = malloc(sizeof(char) * number_of_char);
                if (lineptr_copy == NULL)
                                              {
                        perror("tsh: memory allocation error");
                        return (-1);
                }
                strcpy(lineptr_copy, lineptr);
                token = strtok(lineptr, delim);
                while (token != NULL)
                {
                        num_tokens++;
                        token = strtok(NULL, delim);
                }
                num_tokens++;
                argv = malloc(sizeof(char *) * num_tokens);
                token = strtok(lineptr_copy, delim);
                for (i = 0; token != NULL; i++)
                {
                        argv[i] = malloc(sizeof(char) * strlen(token));
                        strcpy(argv[i], token);
                        token = strtok(NULL, delim);
                }
                argv[i] = NULL;
                pid = fork();
                if (pid == 0)
                {
                        if (execve(argv[0], argv, NULL) == -1)
                                perror("execve");
                }
                else
                        wait(&status);
                num_tokens = 0;
                free(lineptr_copy);
        }
        return (0);