#include "main.h"

#define BUFFER_SIZE 1024

/**
 * execute_command - Handling the PATH and avoiding unnecessary fork.
 * @command: The command to be executed.
 */
void execute_command(char *command);

int main(void) {
    char command[BUFFER_SIZE];

    while (1) {
        if (isatty(STDIN_FILENO)) {
            printf(":) ");
            fflush(stdout);
        }

        if (!fgets(command, BUFFER_SIZE, stdin) || command[0] == '\n') {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (fork() == 0) {
            char *args[] = {command, NULL};
            if (execvp(command, args) == -1) {
                perror(command);
                exit(EXIT_FAILURE);
            }
        } else {
            wait(NULL);
        }
    }

    return 0;
}
