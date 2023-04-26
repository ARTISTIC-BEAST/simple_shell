#include "shell.h"

/**
 * exec_cmd - function name
 * Description: executes executable commands
 * @args: arguments array
 * Return: void
 */

void exec_cmd(char **args)
{
	pid_t pid;

	/*check if command is executable*/
	if (access(args[0], X_OK) != 0)
	{
		printf("%s: No such file or directory\n", args[0]);
		return;
	}
	/*If cmd is execcutable, fork process & execute*/
	pid = fork();
	if (pid == -1)
	{
		/*fork failed*/
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/*child created successfully*/
		execve(args[0], args, NULL);
		/* if execve returns, an error occured*/
		fprintf(stderr, "%s: No such file or directory\n", args[0]);
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}

