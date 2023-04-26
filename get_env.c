#include "shell.h"

/**
 * get_env - get the environment
 * @str: string where the enviroment is
 * Return: Result
 */

char *get_env(char *str)
{

	int i = 0;
	char *copy1 = NULL;
	char **temp = NULL, *res = NULL;
	char *copy2 = NULL;

	(void)str;
	while (environ[i] != NULL)
	{
		copy1 = _strdup(environ[i]);
		temp = split_str(copy1, "=");
		if (_strcmp(temp[0], str) == 0)
		{	copy2 = _strdup(environ[i]);
			res = _strdup(_strchr(copy2, '='));
			free_single(copy2);
		}
		free_single(copy1);
		free_double(temp);
		i++;
	}
	return (res);
}
