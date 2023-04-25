#include "shell.h"

/**
 * _getline - reads an entire line from input
 * Return: the line read from input
 */
char *_getline(void)
{
	char *line = NULL;
	size_t len = 0;
	size_t i = 0;
	int c;

	line = malloc(READ_SIZE);

	if (!line)
		return (NULL);

	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
			break;
		if (i == len)
		{
			len += READ_SIZE;
			line = realloc(line, len);
			if (!line)
				return (NULL);
		}
		line[i++] = c;
	}
	line[i] = '\0';

	return (line);
}
