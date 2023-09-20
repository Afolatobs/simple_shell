#include "shell.h"

/**
 * read_buffer - reads input into a buffer
 * @buffer: the buffer
 * @size: the size
 * Return: ssize_t, number of bytes read
 */
ssize_t read_buffer(char *buffer, size_t size)
{
ssize_t bytes_read = read(STDIN_FILENO, buffer, size);
if (bytes_read < 0)
{
perror("read");
exit(EXIT_FAILURE);
}
return (bytes_read);
}

/**
 * append_char_to_line - appends a character to the line buffer
 * @line: the line
 * @c: the character
 * @line_size: the size of the line
 * Return: char *, the updated line
 */
char *append_char_to_line(char *line, char c, size_t *line_size)
{
char *new_line = realloc(line, (*line_size) + 2);
if (new_line == NULL)
{
perror("realloc");
exit(EXIT_FAILURE);
}
line = new_line;
line[(*line_size)++] = c;
return (line);
}

/**
 * _getline - a command that behaves like getline
 * Return: char *
 */
char *_getline()
{
static char buffer[BUFFER_SIZE];
static size_t buffer_index;
static ssize_t bytes_read;
char *line = NULL;
size_t line_size = 0;
char c;

while (1)
{
if (buffer_index >= (size_t)bytes_read)
{
bytes_read = read_buffer(buffer, sizeof(buffer));
if (bytes_read <= 0)
{
if (line != NULL)
{
free(line);
}
return (NULL);
}
buffer_index = 0;
}
c = buffer[buffer_index++];
if (c == '\n' || c == '\0')
{
if (line != NULL)
{
line[line_size] = '\0';
}
return (line);
}
line = append_char_to_line(line, c, &line_size);
}
}
