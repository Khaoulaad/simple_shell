#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>

extern char **environ;

/*functions_helper*/
int _putchar(char c);
int _strlen(char *s);
char _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
/*prototypes*/
char *_getenv(char *PATH);
int _execute(char *argv[]);
char **_allocate_strtoke(char *value);
int handl_builtin(char *cmd, char **args);
void environment_fnc(char **args __attribute((unused)));
void exit_fnc(char **args);
char *get_path(char *command);
int handle_space_tab(char *cmd);


extern char **__environ;

#endif
