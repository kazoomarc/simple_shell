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

	(void)argc;
	while (1)
	{
		write(1, "#cisfun$ ", 10);
		if (getline(&buf, &n, stdin) == -1 &&
		getline(&buf, &n, stdin) == EOF)
		{
			perror("\n\n\ndisconnected...");
			return (-1);
		} else
		{
			comms = _tokenifier(buf);
			_execute(argv[0], comms);
		}
	}
	free(buf);
	wait(NULL);
	return (0);
}

