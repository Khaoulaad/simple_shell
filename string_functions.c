#include "shell.h"

/**
 * _puts - Prints a string to stdout
 * @str: String to be printed
 *
 * Return: Number of chars printed
*/
int _puts(char *str)
{
	int len = _strlen(str);

	write(STDOUT_FILENO, str, len);

	return (len);
}

/**
 * _strcpy - Copies the string src to dest
 * @dest: Destiny pointer
 * @src: String source
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *mem_address;

	mem_address = dest;

	while (*src != '\0')
	{
		*mem_address = *src;
		mem_address++;
		src++;
	}

	*mem_address = '\0';

	return (dest);
}

/**
 * _strncpy - Ccpoies a string
 * @dest: String to wich chars are going to be copied
 * @src: String to be copied
 * @n: Num of chars to copy from src
 *
 * Return: Pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int count = 0;
	char *start = dest;

	while (*src != '\0' && count < n)
	{
		*(start++) = *(src++);
		count++;
	}

	while (count < n)
	{
		*(start++) = '\0';
		count++;
	}

	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: array
 * Return: length
 */
int _strlen(const char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while (s[i])
		i++;
	return (i);
}

/**
 * _strdup - copy a strings with a malloc
 * @s1: array
 * Return: pointer to the copy
 */
char *_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * _strlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
