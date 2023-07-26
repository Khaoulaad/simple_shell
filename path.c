#include "shell.h"

/**
 * build_file_path - build the full path of a command
 * @path_token: the directory to search
 * @command: the command to find
 *
 * Return: the full path of the command, or NULL if not found
 */
char *build_file_path(char *path_token, char *command)
{
        int command_length = strlen(command);
        int directory_length = strlen(path_token);
        int file_path_length = command_length + directory_length + 2;
        char *file_path = malloc(file_path_length);
        char *ptr = file_path;

        while (*path_token != '\0')
        {
                *ptr = *path_token;
                ptr++;
                path_token++;
        }
        *ptr = '/';
        ptr++;
        while (*command != '\0')
        {
                *ptr = *command;
                ptr++;
                command++;
        }
        *ptr = '\0';

        return (file_path);
}
/**
 * handle_path - find the full path of a command
 * @command: the command to find
 *
 * Return: the full path of the command, or NULL if not found
 */
char *handle_path(char *command)
{
        char *path = _getenv("PATH");
        char *path_copy, *path_token, *file_path;
        struct stat buffer;


        if (path)
        {
                path_copy = strdup(path);
                path_token = strtok(path_copy, ":");


                while (path_token != NULL)
                {
                        file_path = build_file_path(path_token, command);

                        if (stat(file_path, &buffer) == 0)
                        {
                                free(path_copy);
                                return (file_path);
                        }
                        else
                        {
                                free(file_path);
                                path_token = strtok(NULL, ":");
                        }
                }

                free(path_copy);
                if (stat(command, &buffer) == 0)
                        return (command);
        }

        return (NULL);
}
