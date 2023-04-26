#include "shell.h"

/**
 * _env - Prints the current environment.
 *
 * @args: Array of arguments. Unused.
 * @env: Array of environment variables.
 * Return: Always returns 0.
 */
int _env(char **args, char **env)
{
	int i;

	(void)args;
	for (i = 0; env[i]; i++)
		_puts(env[i]), _putchar('\n');
	return (0);
}

/**
 * main - Entry point.
 *
 * @ac: Number of arguments.
 * @av: Array of arguments.
 * @env: Array of environment variables.
 * Return: Always returns 0.
 */
int main(int ac, char **av, char **env)
{
	char *line, **args, *path;
	size_t line_size;
	int status;

	(void)ac, (void)av;
	do {
		line = NULL, args = NULL, line_size = 0;
		_prompt();
		if (getline(&line, &line_size, stdin) == -1)
			break;
		args = _split(line);
		if (!args || !*args || _strcmp(*args, "exit") == 0)
			break;
		if (_strcmp(*args, "env") == 0)
		{
			status = _env(args, env);
		}
		else
		{
			status = _execute(args, env, &path);
			if (status == -1 && path)
			{
				_puts_err(av[0]), _puts_err(": "), _puts_err(args[0]),
				_puts_err(": not found\n"), status = 127;
			}
		}
		if (status != -2 && path)
			free(path);
		free(line), free(args);
	} while (1);
	return (0);
}
