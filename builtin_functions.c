#include "shell.h"

/**
 * exit_fnc - exits the shell
 * @args: arguments
 * Return: void
 */
void exit_fnc(char **args)
{
	int i = 0;

	for (i = 0; args[i] != NULL; i++)
		;
	if (i == 1)
	{
		free(args);
		exit(0);
	}
	else if (i == 2)
	{
		int status = atoi(args[1]);

		free(args);
		exit(status);
	}
	else
	{
		perror("exit does not work");
		free(args);
		exit(2);
	}
}

/**
 * environment_fnc - prints the environment
 * @args: unused arguments
 * Return: void
 */
void environment_fnc(char **args __attribute__((unused)))
{
	int i = 0;

	for (; environ[i] != NULL; i++, _putchar('\n'))
		_puts(environ[i]);
}

/**
 * handl_builtin - handles the built in functions
 * @cmd: command
 * @args: arguments
 * Return: 0 if not found, 1 if found
 */
int handl_builtin(char *cmd, char **args)
{
	if (_strcmp(cmd, "exit") == 0)
	{
		exit_fnc(args);
		return (1);
	}

	if (_strcmp(cmd, "env") == 0)
	{
		environment_fnc(args);
		return (1);
	}
	return (0);
}
