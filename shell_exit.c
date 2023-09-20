#include "shell.h"

/**
 * handleExitCommand - exit command
 * @command: the command
 */
void handleExitCommand(char *command)
{
char *status_str;
int status;

if (strcmp(command, "exit") == 0)
{
free(command);
exit(0);
}
else if (strncmp(command, "exit ", 5) == 0)
{
status_str = command + 5;
status = 0;
while (*status_str != '\0')
{
if (*status_str >= '0' && *status_str <= '9')
{
status = status * 10 + (*status_str - '0');
status_str++;
}
else
{
_printf("Invalid exit command format\n");
break;
}
}
free(command);
exit(status);
}
}
