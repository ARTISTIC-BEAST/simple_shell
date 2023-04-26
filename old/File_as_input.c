#include "shell.h"

/**
 * main - entry point
 * Description: tests program
 * Return: 0
 */

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
	char *filename = NULL;
	char line[MAX_LINE];
	FILE *fp;

	if (argc > 1)
	{
		filename = argv[1];
		fp = fopen(filename, "r");
		if (fp == NULL)
		{
			printf("Error: cannot open file '%s'\n", filename);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		fp = stdin;
	}
	while (fgets(line, MAX_LINE, fp))
	{
		system(line);
	}
	if (filename != NULL)
	{
		fclose(fp);
	}
	return (EXIT_SUCCESS);
}
