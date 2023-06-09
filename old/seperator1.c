include "shell.h"

/**
 * execute - function name
 * Description: executes args
 * @args: args array
 * @env: environment
 * Return: int success
 */

int execute(char **args, char **env)
{
	pid_t pid;
	int status;
	char **tokens;
	int i, j, k;

	if (args[0] == NULL)
		return (1);
	for (i = 0; args[i]; i++)
	{
		tokens = tokenize(args[i], ";");
		for (j = 0; tokens[j]; j++)
		{
			for (k = 0; tokens[j][k]; k++)
			{
				if (tokens[j][k] == '#' && (k == 0 || tokens[j][k - 1] != '\\'))
				{
					tokens[j][k] = '\0';
					break;
				}
			}
			if (tokens[j][0] != '\0')
			{
				if (_strcmp(tokens[j], "exit") == 0)
					exit_shell(tokens, env);
				else if (_strcmp(tokens[j], "env") == 0)
					print_env(env);
				else if (_strcmp(tokens[j], "setenv") == 0)
					set_env(tokens, env);
				else if (_strcmp(tokens[j], "unsetenv") == 0)
					unset_env(tokens, env);
				else if (_strcmp(tokens[j], "cd") == 0)
					change_dir(tokens, env);
				else
				{
					pid = fork();
					if (pid == 0)
					{
						execve(tokens[j], tokens, env);
						perror(tokens[j]);
						exit(127);
					}
					else if (pid < 0)
					{
						perror("fork error");
					}
					else
					{
						do
						{
							waitpid(pid, &status, WUNTRACED);
						}
						while (!WIFEXITED(status) && !WIFSIGNALED(status));
					}
				}
			}
		}
		free_tokens(tokens);
	}
	return (1);
}
