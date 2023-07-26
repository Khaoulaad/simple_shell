#include "khaoulashell.h"

/**
 * tokenize_input - tokenize user input
 * @lineptr: the user input
 * @separator: the delimiter to use
 *
 * Return: an array of tokens
 */
char **tokenize_input(char *lineptr, const char *separator)
{
	char lineptr_copy[10000];
	int num_tokens = 0;
	char *token, **cmd_argv;
	int i;

	strcpy(lineptr_copy, lineptr);
	token = strtok(lineptr, separator);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, separator);
	}

	cmd_argv = malloc(sizeof(char *) * (num_tokens + 1));
	for (i = 0; i < num_tokens; i++)
	{
		cmd_argv[i] = NULL;
	}

	token = strtok(lineptr_copy, " \n\t");
	for (i = 0; token != NULL; i++)
	{
		cmd_argv[i] = _strdup(token);
		token = strtok(NULL, " \n\t");
	}
	cmd_argv[i] = NULL;

	return (cmd_argv);
}
