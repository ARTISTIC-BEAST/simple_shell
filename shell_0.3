#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - Entry point.
 * Return: Always 0.
 */
int main(void)
{
    char *buffer;
    size_t bufsize = 0;
    ssize_t characters;
    char *args[100];
    int i = 0, status;
    pid_t pid;

    while (1)
    {
        printf("($) ");
        characters = getline(&buffer, &bufsize, stdin);
        if (characters == -1)
        {
            free(buffer);
            exit(EXIT_SUCCESS);
        }
        buffer[characters - 1] = '\0';

        args[0] = strtok(buffer, " ");

        i = 1;
        while (i < 100)
        {
            args[i] = strtok(NULL, " ");
            if (args[i] == NULL)
                break;
            i++;
        }

        if (strcmp(args[0], "exit") == 0)
            exit(EXIT_SUCCESS);

        pid = fork();
        if (pid == 0)
        {
            if (execve(args[0], args, NULL) == -1)
            {
                printf("%s: command not found\n", args[0]);
            }
            exit(EXIT_SUCCESS);
        }
        else if (pid < 0)
        {
            perror("Error");
        }
        else
        {
            wait(&status);
        }
    }
    return (0);
}
