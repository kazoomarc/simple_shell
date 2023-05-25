#include "shell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>

/**
 * _execute - implements execve, which hijacks the child process created
 * byour fork command and makes it a proces of itself
 * @argv: This is the name we give to our program on the command line
 * @comms: This is the string  we tokenized from the users input (i.e.
 * the command entered by the user)
 * @stat: status of isatty fxn, tells us if code is from terminal or
 * if it's from CLI
 * @argc: gives us count of arguments in the CLI
 */
void _execute(char *argv, char **comms, int stat, int argc)
{
	pid_t pid;
	int ret;

	pid = fork();
	if (pid == 0)
	{
		if (stat == 1)
		{
			ret = execve(comms[0], comms, NULL);
			if (ret == -1)
			perror(argv);
		}
		if (stat == 0)
		{
			ret = execve(comms[argc - 1], comms, NULL);
			if (ret == -1)
				perror(argv);
		}
	}
	if (pid > 0)
		wait(NULL);
}
