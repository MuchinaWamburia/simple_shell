#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * execute_command - Executes the given command.
 * @command: The command to be executed.
 */
void execute_command(char *command);

int main(void) {
    char command[BUFFER_SIZE];

    while (1) {
        if (isatty(STDIN_FILENO)) {
            printf("#cisfun$ ");
            fflush(stdout);
        }

        if (!fgets(command, BUFFER_SIZE, stdin) || command[0] == '\n') {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (fork() == 0) {
            if (execlp(command, command, (char *)NULL) == -1) {
                perror(command);
                exit(EXIT_FAILURE);
            }
        } else {
            wait(NULL);
        }
    }

    return 0;
}
