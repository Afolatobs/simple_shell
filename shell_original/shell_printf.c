#include "shell.h"

/**
 * _printf - the printf lookalike
 * @str: the string
 */
void _printf(const char *str)
{
	write(1, str, strlen(str));
}
