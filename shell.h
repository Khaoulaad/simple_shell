#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

void handle_cmd(char **argv);
char *handle_path(char *command);
void print_environment(void);
extern char **environ;
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
