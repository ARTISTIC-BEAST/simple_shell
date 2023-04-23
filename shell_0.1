#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - entry point for simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *argv[2];
    pid_t child_pid;
    int status;

    while (1)
    {
        printf("#cisfun$ ");

        /* get command from user */
        if ((read = getline(&line, &len, stdin)) == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        /* remove newline character from command */
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        /* fork child process */
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        /* child process */
        if (child_pid == 0)
        {
            /* execute command */
            argv[0] = line;
            argv[1] = NULL;
            if (execve(argv[0], argv, NULL) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* parent process */
            waitpid(child_pid, &status, 0);
        }
    }

    /* free memory and exit */
    free(line);
    exit(EXIT_SUCCESS);
}
