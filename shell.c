#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"
/**
 * main - main program for simple shell
 * @argc: count of arguments passed into the command line
 * @argv: double pointer to char array containing commands passed to CLI
 * Return: 0 on Succcess
 */
int main(int argc, char **argv)
{
	char **comms;
	char *buf = NULL;
	size_t n;
	int stat = 1;

	while (1)
	{
		write(1, "#cisfun$ ", 10);
		getline(&buf, &n, stdin);
		comms = _tokenifier(buf);
		stat = (isatty(fileno(stdin)));
		if (stat == 1)
		{
			_execute(argv[0], comms, stat, argc);
		} else
		{
			_execute(argv[0], argv, stat, argc);
		}
	}
	free(comms);
	wait(NULL);
	return (0);
}

