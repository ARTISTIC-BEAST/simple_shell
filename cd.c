#include "shell.h"

/**
 * cd_builtin - Changes the current working directory of the process.
 * @args: Array of arguments passed to the function.
 * @env: The environment variables.
 * @status: The status struct.
 *
 * Return: 1 on success, 0 on failure.
 */
int cd_builtin(char **args, char **env, status_t *status)
{
	char *new_dir;
	char old_dir[PATH_MAX];

	if (!args[1])
		new_dir = _getenv("HOME", env);
	else if (_strcmp(args[1], "-") == 0)
	{
		new_dir = _getenv("OLDPWD", env);
		if (!new_dir)
		{
			print_error("cd", "OLDPWD not set", status);
			return (0);
		}
		printf("%s\n", new_dir);
	}
	else
		new_dir = args[1];

	if (chdir(new_dir) == -1)
	{
		print_error("cd", "not a directory", status);
		return (0);
	}

	getcwd(old_dir, sizeof(old_dir));
	setenv("OLDPWD", _getenv("PWD", env), 1);
	setenv("PWD", old_dir, 1);

	return (1);
}
