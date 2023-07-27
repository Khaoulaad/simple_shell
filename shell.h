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
extern char **__environ;

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
void free_and_exit(char *cmd);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void shell_comments(char *cmd);
char *build_file_path(char *path_token, char *command);
char *_getenv(char *PATH);

int _write(int fd, char *inp, int len);
void print_error(char *prog, int *cmdr, char *msg);

int find_n_rep(char **str, char *torep, char *repwith);
int find_tok_occ(char *str, char *tof);

#endif
