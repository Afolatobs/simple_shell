#include "shell.h"

/**
 * tokenize - tokenizer
 * @command: the command
 * Return: A char
 */
char **tokenize(char *command)
{
int arg_count;
char *token;

char **args = malloc((MAX_ARGUMENTS + 1) * sizeof(char *));
if (args == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

arg_count = 0;
token = _strtok(command, " ");

while (token != NULL)
{
if (arg_count >= MAX_ARGUMENTS)
{
_printf("\n");
free(args);
return (NULL);
}

args[arg_count] = strdup(token);
if (args[arg_count] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}

arg_count++;
token = _strtok(NULL, " ");
}

args[arg_count] = NULL;

return (args);
}
