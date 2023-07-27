#include "shell.h"

/**
 * handle_space_tab - check if there is a space or tab in the command
 *@cmd: the command
 *Return: 1 if there is a space or tab, 0 otherwise
 */
int handle_space_tab(char *cmd)
{
	int i = 0;

	while (cmd[i])
	{
		if (cmd[i] == ' ' || cmd[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

/**
 * free_tokens - helper function
 * @tokens: tokens to free
 * Return: nothing
 */
void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/**
 * Function to handle the 'cd' command
 */

void cd_command(char **args)
{
    char *home_dir = getenv("HOME");
    char *current_dir = NULL;
    char *prev_dir = getenv("OLDPWD");
    int ret;

    if (args[1] == NULL || (strcmp(args[1], "-") == 0))
    {
        if (args[1] != NULL && strcmp(args[1], "-") == 0)
        {
            if (prev_dir == NULL)
            {
                perror("cd");
                return;
            }
            printf("%s\n", prev_dir);
            ret = chdir(prev_dir);
        }
        else
        {
            if (home_dir == NULL)
            {
                perror("cd");
                return;
            }
            printf("%s\n", home_dir);
            ret = chdir(home_dir);
        }
    }
    else
    {
        printf("%s\n", args[1]);
        ret = chdir(args[1]);
    }

    if (ret == -1)
        perror("cd");
    else
    {
               current_dir = getcwd(NULL, 0);
        if (current_dir)
        {
            setenv("PWD", current_dir, 1);
            free(current_dir);
        }
    }
}

   /**
 * free_and_exit - frees allocated memory and exits the program
 * @cmd: command string to free
 */
void free_and_exit(char *cmd)
{
	_putchar('\n');
	free(cmd);
	exit(EXIT_SUCCESS);
}

/**
 * main - simple shell
 * @argc: number of arguments
 * @argv: arguments
 * @envp: environment
 * Return: 0 on success
 */
int main(__attribute__((unused)) int argc, char **argv __attribute__((unused)),
		__attribute__((unused)) char **envp)
{
	char *lineptr = NULL, *prompt = "#shell$ ", *token;
	char **token_copy;
	ssize_t len = 0;
	size_t size = 0;
	bool flag = true;


	while (1 && flag)
	{
		if (isatty(STDIN_FILENO) == 0)
			flag = false;
		else
			_puts(prompt);
		if (getline(&lineptr, &size, stdin) == -1)
			free_and_exit(lineptr);
		len = _strlen(lineptr);
		if (len > 0 && lineptr[len - 1] == '\n')
			lineptr[len - 1] = '\0';
		if (len == 1 || lineptr[0] == '\n' || handle_space_tab(lineptr) == 1)
			continue;
		shell_comments(lineptr);
		if (lineptr[0] == '\0')
			continue;
		token = strtok(lineptr, ";\n");
		while (token)
		{
			token_copy = _allocate_strtoke(token);
            if (token_copy[0] == NULL || token_copy[0][0] == '\0')
            {
                token = strtok(NULL, ";\n");
                continue;
            }
            if (strcmp(token_copy[0], "cd") == 0)
            {
                cd_command(token_copy);
            }
            else
            {
                execute_cmd(token_copy); 
            }

            free_tokens(token_copy);
            token = strtok(NULL, ";\n");	
		}
	}
		
	free(lineptr);
	return (0);
}
