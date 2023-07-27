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

#define BUFFER_t 1024

const char *errlist[] = {
	"Undefined error",

	"Operation not permitted",
	"No such file or directory",
	"No such process",
	"Interrupted system call",
	"I/O error",
	"No such device or address",
	"Argument list too long",
	"Exec format error",
	"Bad file number",
	"No child processes",
	"Try again",
	"Out of memory",
	"Permission denied",
	"Bad address",
	"Block device required",
	"Device or resource busy",
	"File exists",
	"Cross-device link",
	"No such device",
	"Not a directory",
	"Is a directory",
	"Invalid argument",
	"File table overflow",
	"Too many open files",
	"Not a typewriter",
	"Text file busy",
	"File too large",
	"No space left on device",
	"Illegal seek",
	"Read-only file system",
	"Too many links",
	"Broken pipe",
	"Too many processes",
	"Too many users",
	"Disc quota exceeded",
	"No locks available",
	"Inappropriate file type or format",
};

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
int _getline(char **lnptr, size_t *size, int fd);
void shell_comments(char *cmd);
char *build_file_path(char *path_token, char *command);
char *_getenv(char *PATH);

int _write(int fd, char *inp, int len);
void print_error(char *prog, int *cmdr, char *msg);

int find_n_rep(char **str, char *torep, char *repwith);
int find_tok_occ(char *str, char *tof);

#endif
