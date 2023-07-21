#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * count_tokens - counts number of tokens in a string
 * @string: string to be tokenized
 * @delim: separators or delimiters
 *
 * Return: The number of nodes in the list.
 */

int count_tokens(char *string, char *delim)
{
        int length = strlen(string);
        int count = 0;
        int i = 0;

        while (i < length)
        {
                while (i < length && strchr(delim, string[i]) != NULL)
                {
                        i++;
                }

                int start_index = i;

                while (i < length && strchr(delim, string[i]) == NULL)
                {
                        i++;
                }

                if (i > start_index)
                {
                        count++;
                }
        }

        return (count);
}

/**
 * tokenize_string - tokenize a string
 * @string: string to be tokenized
 * @delim: separators or delimiters
 * @count: number of tokens
 * Return: The number of nodes in the list.
 */

char **tokenize_string(char *string, char *delim, int *count)
{
        int length = strlen(string);
        *count = count_tokens(string, delim);

        char **strings = malloc(sizeof(char *) * (*count));

        int i = 0;
        int string_index = 0;
        char buffer[10000];

        while (i < length)
        {
                while (i < length && strchr(delim, string[i]) != NULL)
                {
                        i++;
                }

                int j = 0;

                while (i < length && strchr(delim, string[i]) == NULL)
                {
                        buffer[j++] = string[i++];
                }

                if (j > 0)
                {
                        buffer[j] = '\0';
                        int to_allocate = sizeof(char) * (j + 1);

                        strings[string_index] = malloc(to_allocate);
                        strcpy(strings[string_index++], buffer);
                }
        }

        return (strings);
}

/**
 * tokenize - tokenize a string
 * @string: string to be tokenized
 * @delim: separators or delimiters
 * @count: number of tokens
 * Return: The number of nodes in the list.
 */

char **tokenize(char *string, char *delim, int *count)
{
        return (tokenize_string(string, delim, count));
}
