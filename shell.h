#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_getenv(const char *name);
void print_environment(void);
char *build_file_path(char *path_token, char *command);
char *handle_path(char *command);
void execute_cmd(char **argv);
char **tokenize_input(char *lineptr, const char *delim);
void free_cmd_argv(char **cmd_argv);
void run_shell(void);
int _putchar(char c);
#endif
