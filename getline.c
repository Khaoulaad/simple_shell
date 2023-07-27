#include "shell.h"
#define MAX_INPUT_LENGTH 1024

/**
 * _getline - get line of string from file
 * @lineptr: variable to store string
 * @n: number of strings stored
 * @stream: file to read from
 *
 * Return: the lenghh of lnptr or -1 on failure
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytes_read;
	size_t length = 0;
	size_t i;
	static char input_buffer[MAX_INPUT_LENGTH];

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	bytes_read = read(fileno(stream), input_buffer, MAX_INPUT_LENGTH);
	if (bytes_read == -1)
		return (-1);
	while (length < MAX_INPUT_LENGTH && input_buffer[length]
			!= '\n' && input_buffer[length] != '\0')
		length++;
	if (length == 0)
		return (0);
	*lineptr = malloc(length + 1);
	if (*lineptr == NULL)
		return (-1);
	for (i = 0; i < length; i++)
		(*lineptr)[i] = input_buffer[i];
	(*lineptr)[length] = '\0';
	if (n != NULL)
		*n = length;
	return (length);
}
