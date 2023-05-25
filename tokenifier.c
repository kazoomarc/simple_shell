#include "shell.h"
#include <stdlib.h>
#include <string.h>
/**
 * _tokenifier - breaks a string into tokens
 * @txt: string to be broken down into tokens
 * Return: returns a double pointer to a char array containing tokens
 */
char **_tokenifier(char *txt)
{
	char *txt_cpy;
	char *token;
	char **commands;
	int tok_cnt = 0;
	int i = 0;

	if (txt == NULL)
		return (NULL);
	/* allocating mem. for the text to be copied */
	txt_cpy = malloc(sizeof(char) * BUFSIZE);
	if (txt_cpy == NULL)
		return (NULL);
	/* copying text using strcpy */
	_strcpy(txt_cpy, txt);
	/* tokenizing string to get number of tokens for mem. alloc. */
	token = strtok(txt, HSH_DELIM);
	while (token)
	{
		token  = strtok(NULL, HSH_DELIM);
		tok_cnt++;
	}
	commands = malloc(sizeof(char *) * tok_cnt);
	if (commands == NULL)
		return (NULL);
	token = strtok(txt_cpy, HSH_DELIM);
	while (token)
	{
		commands[i] = token;
		token = strtok(NULL, HSH_DELIM);
		i++;
	}
	commands[i] = '\0';
	return (commands);
}
