#include "khaoulashell.h"
/**
 * main - entry point
 *
 * Return: 0 on success, -1 on failure
 */

int main(void)
{
        char *lineptr = NULL, **cmd_argv = NULL;
        size_t n = 0;
        ssize_t number_of_char;
        const char *delim = " \n";
        int interactive_mode = isatty(STDIN_FILENO);

        while (1)
        {
                if (interactive_mode)
                        write(1, "#shell$ ", 8);
                number_of_char = getline(&lineptr, &n, stdin);
                if (number_of_char == EOF)
                {
                        putchar('\n');
                        break;
                }
                cmd_argv = tokenize_input(lineptr, delim);
                if (cmd_argv == NULL)
                {
                        free(lineptr);
                        exit(EXIT_FAILURE);
                }
                if (cmd_argv[0] == NULL || cmd_argv[0][0] == '\0')
                {
                        free_cmd_argv(cmd_argv);
                        continue;
                }
                if (strcmp(cmd_argv[0], "env") == 0)
                        print_environment();
                else if (strcmp(cmd_argv[0], "exit") == 0)
                {
                        free_cmd_argv(cmd_argv);
                        break;
                }
                else
                        execute_cmd(cmd_argv);
                free_cmd_argv(cmd_argv);
        }
        free(lineptr);
        return (0);
}
