#include "shell.h"

/**
 * my_setenv - my setenv
 * @name: the name of the env
 * @value: the value
 * Return: the integer
 */
int my_setenv(const char *name, const char *value)
{
if (setenv(name, value, 1) == -1)
{
_printf("Failed \n");
return (1);
}
return (0);
}

/**
 * my_unsetenv - the unsetenv
 * @name: the name
 * Return: integer
 */
int my_unsetenv(const char *name)
{
if (unsetenv(name) == -1)
{
_printf("Failed \n");
return (1);
}
return (0);
}
