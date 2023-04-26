#include "shell.h"

/**
 * main - Entry point
 * Description: tests program
 * Return: 0
 */

#define BUFSIZE 1024

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_line;
	const char *delim = " \n";
	char **args; /*holds cmd and NULL*/

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			printf("#cisfun$ ");
			read_line = getline(&line, &len, stdin);
			if (read_line == -1)
			{
				/*EOF*/
				printf("\n");
				exit(0);
			}
			/*replace newline with NULL terminator*/
			line[read_line - 1] = '\0';
			/*set command and NULL in args array*/
			args = split_string(line, delim);
			exec_cmd(args); /*execute command*/
		}
	}
	else
	{
		while (getline(&line, &len, stdin) != -1)
		{
			/*remove newline character*/
			line[strlen(line) - 1] = '\0';
			system(line);
		}
	}
	free(line); /*free mem automatically allocated by getline*/
	return(0);
}
