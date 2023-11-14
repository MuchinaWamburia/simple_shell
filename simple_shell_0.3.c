#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - a shell program that Handles the PATH
 * Return: Always 0
 */
int main(void)
{
char command[BUFFER_SIZE];
char *path = "/bin/";


while (1)
{
printf(":) ");

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
char *full_path = malloc(strlen(path) + strlen(args[0]) + 1);
strcpy(full_path, path);
strcat(full_path, args[0]);

if (access(full_path, X_OK) == 0)
{
if (execve(full_path, args, NULL) == -1) 
{
perror("Error");
exit(EXIT_FAILURE);
}
}
else
{
printf("%s: No such file or directory\n", args[0]);
free(full_path);
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
