#include "shell.h"

/**
 * handleCdCommand - handle the cd part3
 * @command: the command
 * Return: the integer
 */
int handleCdCommand(char *command)
{
char *args;

if (strncmp(command, "cd", 2) == 0)
{
args = _strtok(command, " \t\n");
args = _strtok(NULL, " \t\n");

return (handleCdLogic(args));
}

return (-1);
}
