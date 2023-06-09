#include "shell.h"

/**
 * main - Entry point
 * Description: tests projects
 * Return: 0
 */

#define BUFFER_SIZE 1024

int main(void)
{
	char *input, *token;
	char *args[100];
	char buffer[BUFFER_SIZE];
	int i, j, k;
	int exit_shell = 0;

	while (!exit_shell)
	{
		printf("$ ");
		/* Read input from user*/
		input = fgets(buffer, BUFFER_SIZE, stdin);
		
		if (!input)
		{
			printf("\n");
			break;
		}
		/* Remove newline character*/
		input[strlen(input) - 1] = '\0';
		/* Check for comments and remove them*/
		for (i = 0; input[i] != '\0'; i++)
		{
			if (input[i] == '#')
			{
				input[i] = '\0';
				break;
			}
		}
		/* Tokenize input into arguments*/
		token = strtok(input, " ");
		i = 0;
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		/* Handle built-in commands*/
		if (strcmp(args[0], "exit") == 0)
		{
			exit_shell = 1;
		}
		else if (strcmp(args[0], "cd") == 0)
		{
			if (args[1])
			{
				if (chdir(args[1]) != 0)
				{
				perror("cd");
				}
			}
			else
			{
				chdir(getenv("HOME"));
			}
		}
		else if (strcmp(args[0], "pwd") == 0)
		{
			char cwd[1024];
			if (getcwd(cwd, sizeof(cwd)) != NULL)
			{
				printf("%s\n", cwd);
			}
			else
			{
				perror("getcwd");
			}
		}
		else
		{
			/* Handle external commands*/
			int pid = fork();
			if (pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					perror("execvp");
					exit(EXIT_FAILURE);
				}
			}
			else if (pid < 0)
			{
				perror("fork");
			}
			else
			{
				wait(NULL);
			}
		}
	}
	return (0);
}
