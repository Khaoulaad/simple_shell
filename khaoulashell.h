#ifndef KHAOULASHELL_H
#define KHAOULASHELL_H

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
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strchr(char *s, char c);
char *_strdup(char *str);
#endif
