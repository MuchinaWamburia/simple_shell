#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void execute_command(char *command);
void builtin_exit(void);
void builtin_env(void);
int main(void);

#endif /* MAIN_H
*/
