#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * display_prompt - Display the prompt
 * @is_first: Flag indicating whether this is the first prompt displayed
 *
 */
void display_prompt(int is_first)
{
    if (isatty(STDIN_FILENO) || is_first) {
        printf("#Ownshell$ ");
    }
}

/**
 * read_input - Read input from the user
 * Return: The input string
 *
 */
char *read_input(void)
{
    char *input = NULL;
    size_t size = 0;

    if (getline(&input, &size, stdin) == -1) {
        free(input);
        return NULL;
    }

    return input;
}

/**
 * execute_command - Execute the command
 * @command: The command string
 *
 *
 */
void execute_command(char *command)
{
    char *args[] = {command, NULL};
    char **environ;

    if (execve(command, args, environ) == -1) {
        perror("Shell");
    }
    exit(EXIT_FAILURE);
}

/**
 * run_command - Run the command
 * @command: The command string
 *
 */
void run_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        execute_command(command);
    } else if (pid < 0) {
        perror("Error");
    } else {
        wait(&status);
    }
}

/**
 * main - Entry point of the program
 * Return: 0 on success
 *
 */
int main(void)
{
    char *input;
    char *command;
    int is_first = 1;

    while (1) {
        display_prompt(is_first);
        is_first = 0;

        input = read_input();

        if (input == NULL) {
            printf("\n");
            break;
        }

        command = strchr(input, '\n');

        if (command == NULL) {
            free(input);
            continue;
        }

        *command = '\0';
        command = input;

        run_command(command);
        free(input);
    }

    return 0;
}
