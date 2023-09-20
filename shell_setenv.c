#include "shell.h"

/**
 *  handleShellCommands - some shell command
 *  @command: the command
 */
void handleShellCommands(char *command)
{
char *arg;
char *name;
char *value;

if (strncmp(command, "setenv ", 7) == 0)
{
arg = command + 7;
name = _strtok(arg, " ");
value = _strtok(NULL, " ");

if (name != NULL && value != NULL)
{
my_setenv(name, value);
}
else
{
_printf("Usage: setenv VARIABLE\n");
}
}
else if (strncmp(command, "unsetenv ", 9) == 0)
{
name = command + 9;
if (name != NULL)
{
my_unsetenv(name);
}
else
{
_printf("Usage: unsetenv VARIABLE\n");
}
}
}
