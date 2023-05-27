#include "shell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _execute - implements execve, which hijacks the child process created
 * byour fork command and makes it a proces of itself
 * @argv: This is the name we give to our program on the command line
 * @comms: This is the string  we tokenized from the users input (i.e.
 * the command entered by the user)
 */
void _execute(char *argv, char **comms)
{
	pid_t pid;
	int ret;

	pid = fork();
	if (pid == 0)
	{
		ret = execve(comms[0], comms, environ);
		if (ret == -1)
		{
			free(comms);
			perror(argv);
		}
	}
	if (pid > 0)
		wait(NULL);
}
