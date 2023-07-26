#include "shell.h"

/**
 * free_cmd_argv - free memory allocated for command arguments
 * @cmd_argv: the command arguments
 */
void free_cmd_argv(char **cmd_argv)
{
	int i;

	if (cmd_argv == NULL)
		return;

	for (i = 0; cmd_argv[i] != NULL; i++)
		free(cmd_argv[i]);
	free(cmd_argv);
}
