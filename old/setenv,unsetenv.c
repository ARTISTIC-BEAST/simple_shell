#include "shell.h"

/**
 * setenv_builtin - sets the value of an environment variable
 * @args: array of arguments to the setenv command
 *
 * Return: always returns 1, to continue execution
 */
int setenv_builtin(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
	}
	else
	{
		setenv(args[1], args[2] != NULL ? args[2] : "", 1);
	}
	return (1);
}

/**
 * unsetenv_builtin - unsets an environment variable
 * @args: array of arguments to the unsetenv command
 *
 * Return: always returns 1, to continue execution
 */
int unsetenv_builtin(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
	}
	else
	{
		unsetenv(args[1]);
	}
	return (1);
}
