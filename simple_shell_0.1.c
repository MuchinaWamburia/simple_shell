#include "main.h"

int main(void)
{
    char command[BUFFER_SIZE];

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            printf("#cisfun$ ");
            fflush(stdout);
        }

        if (!fgets(command, BUFFER_SIZE, stdin) || command[0] == '\n')
        {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (fork() == 0)
        {
            if (execlp(command, command, (char *)NULL) == -1)
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
