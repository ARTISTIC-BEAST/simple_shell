#include "shell.h"

/**
 * main - entry point
 * Description: executes lines
 * Return: status
 */

#define MAX_ARGS 512
#define MAX_ARG_LENGTH 4096
#define MAX_LINE_LENGTH 4096

int execute_command(char **args, int bg);
int execute_line(char **args);
int parse_line(char *line, char **args);
void free_args(char **args);

int main(void)
{
	char line[MAX_LINE_LENGTH];
	char *args[MAX_ARGS];
	int status = 0;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (!fgets(line, MAX_LINE_LENGTH, stdin))
		{
			break;
		}
		status = execute_line(parse_line(line, args));
		free_args(args);
	}
	return (status);
}


/**
 * execute_command - new function
 * Description: executes commands
 * @args: ptr to array of args
 * @bg: bg arg
 * Return: status
 */

int execute_command(char **args, int bg)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) < 0)
		{
			perror("execvp");
			exit(1);
		}
	}
	if (!bg)
	{
		while (waitpid(pid, &status, 0) < 0)
		{
			if (errno != EINTR)
			{
				status = -1;
				break;
			}
		}
	}
	return (status);
}


/**
 * execute_line - new function
 * Description: executes line
 * @args: ptr to args array
 * Return: status
 */

int execute_line(char **args)
{
	int i, status = 0, bg = 0;
	char **prev_args = NULL;

	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], "&&") == 0)
		{
			if (status == 0)
			{
				if (prev_args != NULL)
				{
					free_args(prev_args);
				}
				prev_args = &args[i + 1];
			}
			else
			{
				free_args(args);
				return (status);
			}
		}
		else if (strcmp(args[i], "||") == 0)
		{
			if (status != 0)
			{
				if (prev_args != NULL)
				{
					free_args(prev_args);
				}
				prev_args = &args[i + 1];
			}
			else
			{
				free_args(args);
				return (status);
			}
		}
		else if (strcmp(args[i], "&") == 0)
		{
			bg = 1;
		}
		else
		{
			status = execute_command(args + i, bg);
			bg = 0;
		}
	}
	if (prev_args != NULL)
	{
		status = execute_line(prev_args);
	}

	return (status);
}

/**
 * parse_line - new function
 * Description: parses line
 * @line: ptr to line
 * @args: ptr to args array
 * Return: args count
 */

int parse_line(char *line, char **args)
{
	int argc = 0;
	char *arg = strtok(line, " \t\n");

	while (arg != NULL)
	{
		args[argc++] = strdup(arg);
		arg = strtok(NULL, " \t\n");
	}
	args[argc] = NULL;
	return (argc);
}

/**
 * free_args - new function
 * Description: frees allocated memory
 * @args: ptr to args array
 * Return: void
 */

void free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
}
