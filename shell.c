#include "shell.h"

/**
 * main - A shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char *command;
	char **args;

	while (1)
	{
		_prompt();
		command = _getline();
		if (command == NULL)
		{
			_printf("\n");
			break;
		}

		if (handleCdCommand(command) == 0)
		{
			free(command);
			continue;
		}
		handleShellCommands(command);
		handleExitCommand(command);

		args = tokenize(command);

		if (args != NULL)
		{
			_exec(args);
			free(args);
		}
		free(command);
	}
	return (0);
}
