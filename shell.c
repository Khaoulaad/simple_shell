#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void display_prompt(int is_first);

char *read_buffer(void);

void execute_command(char *command);
void run_command(char *command);

/**
 * display_prompt - Display the prompt
 * @prompt: Flag indicating whether this is the first prompt displayed
 *
 * This function displays the prompt "#cisfun$ " if it's the first prompt or
 * when the input comes from the terminal.
 */
void display_prompt(int prompt)
{
        if (isatty(STDIN_FILENO) || prompt)
        {
                printf("#Ownshell$ ");
        }
}

/**
 * read_buffer - Read input from the user
 * Return: The input string
 *
 */
char *read_buffer(void)
{
        char *buffer = NULL;
        size_t size = 0;

        if (getline(&buffer, &size, stdin) == -1)
        {
                free(buffer);
                return (0);
        }

        return (buffer);
}

/**
 * execute_command - Execute the command
 * @command: The command string
 *
 */
void execute_command(char *command)
{
        char *args[] = {command, NULL};
        char **environ;

        if (execve(command, args, environ) == -1)
        {
                perror("./Shell");
        }
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

        if (pid == 0)
        {
                execute_command(command);
        }
        else if (pid < 0)
        {
                perror("Error");
        }
        else
        {
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
        char *buffer;
        char *command;
        int prompt = 1;

        while (1)
        {
                display_prompt(prompt);
                prompt = 0;

                buffer = read_buffer();

                if (buffer == NULL)
                {
                        printf("\n");
                        break;
                }

                command = strchr(buffer, '\n');

                if (command == NULL)
                {
                        free(buffer);
                        continue;
                }

                *command = '\0';
                command = buffer;

                run_command(command);
                free(buffer);
        }

        return (0);
}
