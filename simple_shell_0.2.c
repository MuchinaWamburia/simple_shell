#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - a shell program that Handles command lines with arguments
 * Return: Always 0
 */
int main(void)
{
char command[BUFFER_SIZE];

while (1)
{
printf("c programming is fun");

if (!fgets(command, BUFFER_SIZE, stdin) || command[0] == '\n')
{
break;
}

command[strcspn(command, "\n")] = '\0';
char *args[BUFFER_SIZE / 2];
int i = 0;
char *token = strtok(command, " ");
while (token != NULL && i < BUFFER_SIZE / 2 - 1)

{
args[i] = token;
token = strtok(NULL, " ");
i++;
}

args[i] = NULL;
if (fork() == 0)
{
if (execve(args[0], args) == -1)
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
