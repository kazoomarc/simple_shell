#include "shell.h"
#include <stddef.h>
#include <unistd.h>
/**
 * _strcpy - copies strings from src to dest including null bytes
 * @dest: destination where strings are to be copied to
 * @src: buffer where strings to be copied is saved
 * Return: returns a char pointer to the dest
 */

char *_strcpy(char *dest, char const *src)
{
	if (src == NULL || dest == NULL)
	{
		return (NULL);
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

/**
 * _putchar - prints out 1 char at a time to stdout
 * @c: char to be printed out
 * Return: returns the char. passed into the function
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}

