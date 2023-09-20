#include "shell.h"

/**
 * fileExistsInDirectory - the exit directory
 * @directory: the directory
 * @command: the command
 * Return: A bool
 */
bool fileExistsInDirectory(const char *directory, const char *command)
{
char path[MAX_PATH_LENGTH];
int len = strlen(directory);

if (len + strlen(command) + 2 > MAX_PATH_LENGTH)
{
write(STDERR_FILENO, "Path too long\n", 14);
exit(EXIT_FAILURE);
}

strcpy(path, directory);
path[len] = '/';
strcpy(path + len + 1, command);

return (access(path, X_OK) != -1);
}

/**
 * findCommandInPath - find the path
 * @command: the command
 * Return: a character pointer
 */
char *findCommandInPath(const char *command)
{
char *path = getenv("PATH");
char *path_copy = strdup(path);
char *token = _strtok(path_copy, ":");
char *full_path;

while (token != NULL)
{
if (fileExistsInDirectory(token, command))
{
full_path = malloc(strlen(token) + strlen(command) + 2);
strcpy(full_path, token);
strcat(full_path, "/");
strcat(full_path, command);
free(path_copy);
return (full_path);
}
token = _strtok(NULL, ":");
}

free(path_copy);
return (NULL);
}
