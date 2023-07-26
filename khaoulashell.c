#include "khaoulashell.h"
/**
 * main - entry point
 *
 * Return: 0 on success, -1 on failure
 */
static void process_interactive_input(void)
{
	char *lineptr = NULL, **cmd_argv = NULL;
	size_t n = 0;
	ssize_t number_of_char;
	const char *delim = " \n";

	while (1)
	{
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
			return;
		}
		if (cmd_argv[0] == NULL || cmd_argv[0][0] == '\0')
		{
			free_cmd_argv(cmd_argv);
			continue;
		}
		if (_strcmp(cmd_argv[0], "env") == 0)
			print_environment();
		else if (_strcmp(cmd_argv[0], "exit") == 0)
		{
			free_cmd_argv(cmd_argv);
			break;
		}
		else
			execute_cmd(cmd_argv);
		free_cmd_argv(cmd_argv);
	}

	free(lineptr);
}

static void process_script_input(const char *script_file_path)
{
	char *lineptr = NULL, **cmd_argv = NULL;
	size_t n = 0;
	ssize_t number_of_char;
	const char *delim = " \n";


	FILE *script_file = fopen(script_file_path, "r");

	if (script_file == NULL)
	{
		perror("Error opening script file");
		return;
	}

	while ((number_of_char = getline(&lineptr, &n, script_file)) != EOF)
	{
		cmd_argv = tokenize_input(lineptr, delim);
		if (cmd_argv == NULL)
		{
			free(lineptr);
			fclose(script_file);
			return;
		}
		if (cmd_argv[0] != NULL && cmd_argv[0][0] != '\0')
		{
			if (_strcmp(cmd_argv[0], "env") == 0)
				print_environment();
			else if (_strcmp(cmd_argv[0], "exit") == 0)
			{
				free_cmd_argv(cmd_argv);
				break;
			}
			else
				execute_cmd(cmd_argv);
		}
		free_cmd_argv(cmd_argv);
	}
	fclose(script_file);
	free(lineptr);
}

int main(int argc, char *argv[])
{
	int interactive_mode = isatty(STDIN_FILENO);

	if (!interactive_mode && argc > 1)
	{
		process_script_input(argv[1]);
	} else
	{
		process_interactive_input();
	}

	return (0);
}

