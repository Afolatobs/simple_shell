#include "shell.h"

/**
*changeDirectory - change directory
*@newDir: the dir
*Return: the integer
*/
int changeDirectory(const char *newDir)
{
char current_directory[1024];

if (chdir(newDir) != 0)
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

if (setenv("PWD", newDir, 1) != 0)
{
perror("setenv");
return (-1);
}

return (0);
}

/**
*handleCdLogic - the logic
*@args: the arg
*Return: integer
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

if (args != NULL)
{
return (changeDirectory(args));
}

return (-1);
}
