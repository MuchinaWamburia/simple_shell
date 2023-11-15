#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - a simple shell program that prints "hello im lucy"
 * Return: Always 0
 */
int main(void)
{
char command[BUFFER_SIZE];
char *args[2];

while (1)
{
printf("($) ");

if (!fgets(command, BUFFER_SIZE, stdin) || command[0] == '\n')
{
break;
}
command[strcspn(command, "\n")] = '\0';

if (fork() == 0)
{
if (execve(command, args, NULL) == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
}
return (0);
}
