#include "shell.h"

/**
 * handle_space_tab - check if there is a space or tab in the command
 *@cmd: the command
 *Return: 1 if there is a space or tab, 0 otherwise
 */
int handle_space_tab(char *cmd)
{
	int i = 0;

	while (cmd[i])
	{
		if (cmd[i] == ' ' || cmd[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

/**
 * free_tokens - helper function
 * @tokens: tokens to free
 * Return: nothing
 */
void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
/**
 * free_and_exit - frees allocated memory and exits the program
 * @cmd: command string to free
 */
void free_and_exit(char *cmd)
{
	_putchar('\n');
	free(cmd);
	exit(EXIT_SUCCESS);
}

/**
 * main - simple shell
 * @argc: number of arguments
 * @argv: arguments
 * @envp: environment
 * Return: 0 on success
 */
int main(__attribute__((unused)) int argc, char **argv __attribute__((unused)),
		__attribute__((unused)) char **envp)
{
	char *lineptr = NULL, *prompt = "#shell$ ", *token;
	char **token_copy;
	ssize_t len = 0;
	size_t size = 0;
	bool flag = true;

	while (1 && flag)
	{
		if (isatty(STDIN_FILENO) == 0)
			flag = false;
		else
			_puts(prompt);
		if (_getline(&lineptr, &size, stdin) == -1)
			free_and_exit(lineptr);
		len = _strlen(lineptr);
		if (len > 0 && lineptr[len - 1] == '\n')
			lineptr[len - 1] = '\0';
		if (len == 1 || lineptr[0] == '\n' || handle_space_tab(lineptr) == 1)
			continue;
		shell_comments(lineptr);
		if (lineptr[0] == '\0')
			continue;
		token = strtok(lineptr, ";\n");
		while (token)
		{
			token_copy = _allocate_strtoke(token);
			if (token_copy[0] == NULL || token_copy[0][0] == '\0')
			{
				token = strtok(NULL, ";\n");
				continue;
			}
			_execute(token_copy);
			free_tokens(token_copy);
			token = strtok(NULL, ";\n");
		}
	}
	free(lineptr);
	return (0);
}
