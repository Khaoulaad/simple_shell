#include "shell.h"

/**
 * _getline - get line of string from file
 * @lnptr: variable to store string
 * @size: number of strings stored
 * @fd: file to read from
 *
 * Return: the lenghh of lnptr or -1 on failure
 */

int _getline(char **lineptr, size_t *size, int fd)
{
	char buffer[BUFFER_t + 1];
	int r = BUFFER_t, len = 0, mode = isatty(0);
	char *tmp;

	*lineptr = (char *)_malloc(4);
	**lineptr = '\0';
	while (r == BUFFER_t)
	{
		if (*lineptr && len > 0)
			if ((*lineptr)[len - 1] == '\n' && mode)
				break;
		r = read(fd, buffer, BUFFER_t);
		if (r < 0 && errno == EINTR)
		{
			**lineptr = '\n',	*(*lineptr + 1) = '\n', len = 2;
			return (len);
		}
		if (r < 0)
			exit(-1);
		if (r == 0 && mode)
			return (-1);
		tmp = _realloc(*lineptr, len + r + 4);
		*size = len + r + 4, *lineptr = tmp;
		buffer[r] = '\0', _strcat(*lineptr, buffer), len += r;
		if (!mode)
			find_n_rep(lineptr, "\n", ";");
	}
	if (!mode)
	{
		tmp = _realloc(*lineptr, _strlen(*lineptr) + 3);
		*lineptr = tmp;
		(*lineptr)[len] = '\n', (*lineptr)[len + 1] = '\0';
	}
	return (len);
}
