#include "shell.h"

/**
 * env_builtin - Prints the current environment
 *
 * Return: Always returns 0
 */
int env_builtin(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}
