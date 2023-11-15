#include "main.h"

int main(void)
{
    char command[BUFFER_SIZE];

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            printf(":) ");
            fflush(stdout);
        }

        if (!fgets(command, BUFFER_SIZE, stdin) || command[0] == '\n')
        {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (fork() == 0)
        {
            char *args[2];
            args[0] = command;
            args[1] = NULL;
            if (execvp(command, args) == -1)
            {
                perror(command);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}
