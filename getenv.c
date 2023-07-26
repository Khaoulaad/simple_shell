#include "shell.h"

/**
 * _getenv - get the value of an environment variable
 * @name: the name of the variable
 *
 * Return: a pointer to the value of the variable, or NULL if not found
 */
char *_getenv(const char *name)
{
	char **env;
	size_t name_len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&((*env)[name_len + 1]));
		}
	}

	return (NULL);
}
