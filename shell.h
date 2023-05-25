#ifndef SHELL_H
#define SHELL_H
#define BUFSIZE 1024
#define HSH_DELIM " \n\t\r"
#include <stddef.h>

char *_strcpy(char *, const char *src);
int _putchar(int c);
char **_tokenifier(char *);
void _execute(char *, char **, int, int);

#endif /* end #ifndef SHELL_H */
