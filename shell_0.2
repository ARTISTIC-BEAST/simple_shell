#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFSIZE 1024

int main(void)
{
	char *args[BUFSIZE / 2 + 1];
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	pid_t pid;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		nread = getline(&line, &bufsize, stdin);
		if (nread == -1)
			break;
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		char *token = strtok(line, " ");
		int i = 0;
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		pid = fork();

		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			perror("Error");
		else
			wait(&status);
	}
	free(line);
	exit(EXIT_SUCCESS);
}
