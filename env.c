#include "shell.h"

/**
 * print_environment - print the environment variables
 */
void print_environment(void)
{
        char **env, *str;

        for (env = environ; *env != NULL; env++)
        {
                str = *env;
                while (*str != '\0')
                {
                        putchar(*str);
                        str++;
                }
                putchar('\n');
        }
}
