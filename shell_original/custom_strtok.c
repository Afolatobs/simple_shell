#include "shell.h"

/**
 * _strtok - behaves like a strtok fuction
 * @str: the string
 * @delim: the delimeter
 * Return: character pointer
 */
char *_strtok(char *str, const char *delim)
{
static char *lastToken;
char *tokenEnd;

if (!str)
str = lastToken;

if (!str)
return (NULL);

str += strspn(str, delim);

if (*str == '\0')
{
lastToken = NULL;
return (NULL);
}
tokenEnd = str + strcspn(str, delim);
if (*tokenEnd != '\0')
{
*tokenEnd = '\0';
lastToken = tokenEnd + 1;
}
else
{
lastToken = NULL;
}

return (str);
}
