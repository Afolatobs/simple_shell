#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints a pattern of asterisks to the console.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int rows = 5;
int i, j;

for (i = 0; i < rows; i++)
{
for (j = 0; j < rows - i - 1; j++)
{
printf(" ");
}
for (j = 0; j < 2 * i + 1; j++)
{
printf("*");
}
printf("\n");
}

return (0);
}
