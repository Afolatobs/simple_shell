#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 1024
#define MAX_ENV_VARS 100
#define MAX_ARGUMENTS 64

void _printf(const char *str);
void _prompt(void);
char *_read(void);
char **tokenize(char *command);
void _exec(char **args);
char *find_executable(char *command);
bool fileExistsInDirectory(const char *directory, const char *command);
char *findCommandInPath(const char *command);
void executeEnv(void);
char *_getline();
char *_strtok(char *str, const char *delim);
void handleExitCommand(char *command);
void handleShellCommands(char *command);
int my_setenv(const char *name, const char *value);
int my_unsetenv(const char *name);
int my_cd(const char *path);
int cd_command(char *directory);
int handleCdLogic(char *args);
int handleCdCommand(char *command);
int processAndExecuteCommands(char *command);
char *trim(char *str);
int changeDirectory(const char *newDir);
ssize_t read_buffer(char *buffer, size_t size);
char *append_char_to_line(char *line, char c, size_t *line_size);

#endif
