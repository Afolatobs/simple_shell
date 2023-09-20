#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * executeEnv - execute the environment variable
 */
void executeEnv(void)
{
char **env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}

/**
 * _exec - the executable file
 * @args: the command
 */
void _exec(char **args)
{
int status;
pid_t my_pid;
char *full_path;

if (args[0] != NULL && strcmp(args[0], "env") == 0)
{
executeEnv();
return;
}
full_path = findCommandInPath(args[0]);
if (full_path == NULL)
{
_printf("cd\n");
return;
}
my_pid = fork();
if (my_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (my_pid == 0)
{
if (execve(full_path, args, NULL) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
if (wait(&status) == -1)
{
perror("wait");
exit(EXIT_FAILURE);
}
}
free(full_path);
}
