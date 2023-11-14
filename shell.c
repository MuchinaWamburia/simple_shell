#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - a shell program that executes user commands
 * Return: Always 0
 */
int main(void)
{
char command[BUFFER_SIZE];
char *args[2];

while (1)
{
printf("C programming is fun");

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
