#include "shell.h"
#include "error.h"

/**
 * printerror - print error message
 * @prog: command
 * @cmdr: pointer to error
 * @message: error message
 *
 * Return: none
 */

void printerror(char *prog, int *cmdr, char *message)
{
	char *numcomd;
	static int *cmdsrun;
	static char *progname;

	if (!message)
	{
		cmdsrun =  cmdr;
		progname = prog;
		return;
	}
	if (!cmdr || !prog)
	{
		_write(-1, NULL, 0);
		_write(2, progname, _strlen(progname) + 1);
		_write(2, ": ", 2);
		numcomd = itoa(*cmdsrun);
		_write(2, numcomd, _strlen(numcomd));
		free(numcomd);
		_write(2, ": ", 2);
		_write(2, prog, _strlen(prog));
		_write(2, ": ", 2);
		_write(2, message, _strlen(message));
		_write(2, "\n", 1);
		_write(2, NULL, 0);
	}
}
