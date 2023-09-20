#include "shell.h"

/**
 * handleCdLogic - handles the change of directory
 * @args: the argument or character it takes
 * Return: an integer
 */
int handleCdLogic(char *args)
{
if (args == NULL)
{
args = getenv("HOME");
if (args == NULL)
{
_printf("HOME environment variable not set.\n");
return (-1);
}
}
else if (strcmp(args, "-") == 0)
{
args = getenv("OLDPWD");
if (args == NULL)
{
_printf("OLDPWD environment variable not set.\n");
return (-1);
}
}

return (changeDirectory(args));
}

/**
 * changeDirectory - change the directory path
 * @args: the argument or character
 * Return: the integer
 */
int changeDirectory(char *args)
{
char current_directory[1024];

if (args != NULL)
{
if (chdir(args) != 0)
{
perror("chdir");
return (-1);
}

if (getcwd(current_directory, sizeof(current_directory)) == NULL)
{
perror("getcwd");
return (-1);
}

if (setenv("OLDPWD", current_directory, 1) != 0)
{
perror("setenv");
return (-1);
}

if (setenv("PWD", args, 1) != 0)
{
perror("setenv");
return (-1);
}
return (0);
}
return (-1);
}
