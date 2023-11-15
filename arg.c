#include <stdio.h>

/**
 * main - program that prints all the arguments
 * @argc: number of command-line arguments.
 * @argv: array of strings containing the arguments.
 * Return:  always 0
 */
int main(int argc, char *argv[])
{
if (argc > 1)
{
for (int i = 1; i < argc; i++)
printf("%s ", argv[i]);
}
printf("\n");
}
else
{
printf("No arguments provided.\n");
}
return (0);
}
