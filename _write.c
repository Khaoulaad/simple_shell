#include "shell.h"

/**
 * _write - write to field descriptor
 * @filedescriptor: field descriptor
 * @inp: string to write
 * @len: number of chars in string
 *
 * Return: -100 when no queue, 100 when sucessfully write to
 */

int _write(int filedescriptor, char *inp, int len)
{

	static char writeq[BUFFER_t];
	static int nq;
	int i;

	if (filedescriptor < 0)
	{
		nq = 0;
		return (-100);
	}
	if (inp)
	{
		if ((len + nq) >= BUFFER_t)
		{
			if (write(filedescriptor, writeq, BUFFER_t) == -1)
			{
				print_error(NULL, NULL, "problem writing");
				exit(-1);
			}
			nq = 0;
		}
		i = 0;
		while (i < len)
		{
			writeq[nq + i] = inp[i];
			i++;
		}
		writeq[nq + i] = '\0';
		nq += len;
		return (100);
	}
	if (!inp)
		if (write(filedescriptor, writeq, nq) == -1)
		{
			print_error(NULL, NULL, "problem writing");
			exit(-1);
		}
	return (0);
}
