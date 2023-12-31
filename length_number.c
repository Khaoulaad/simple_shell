#include "shell.h"

/**
 * num_length- return length of stringized number
 * @num : number
 * Return: no. of digits
 */

int num_length(unsigned int num)
{
	int length = 0;

	if (!num)
		return (1);

	while (num)
	{
		num = num / 10;
		length += 1;
	}

	return (length);
}
