#include "shell.h"

/**
 * run_command - execute a command
 * @cmd: the command to execute
 *
 * Return: 0 on success, -1 on failure
 */
int run_command(char *cmd)
{
	pid_t pid;
	char **args;
	int status;

	args = split_string(cmd, " ");
	if (args == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(args);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(args);
	return (0);
}
