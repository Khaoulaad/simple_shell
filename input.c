#include "shell.h"

/**
 * getinput - take input from the command line
 * @input: pointer to input str
 * @inputlengh: pointer to input lengh
 * @cmds: pointer to array of arguments
 * @fd: file discriptor
 *
 * Return: lenght of input
 */

int getinput(char **input, size_t *inputlengh, char ***cmds, int fd)
{
	int lengh;

	if (isatty(0) && !fd)
		write(1, "$ ", 2);
	lengh = _getline(input, inputlengh, fd);
	if (lengh == -1)
	{
		free(*input);
		write(1, "\n", 1);
		exit(0);
	}
	(*input)[lengh - 1] = '\0';
	parse_args(*input, ";", cmds, 0);
	return (lengh - 1);
}
