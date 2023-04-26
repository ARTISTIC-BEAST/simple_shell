#include "shell.h"

/**
 * split_string - new function
 * Description: handles command line arguments
 * @line: ptr to the entered line
 * @delim: the delimeter to split line
 * Return: array of arguments
 */

char **split_string(char *line, const char *delim)
{
	char **args = NULL; /*Array holding arguments*/
	char *token = strtok(line, delim); /*split line 2 tokens*/
	int index = 0; /*index variable*/

	while (token != NULL) /*because strtok returns NULL when toks are finished*/
	{
		args = realloc(args, sizeof(char *) * (index + 1));
		args[index] = token; /*each token is an individual element */
		index++;
		token = strtok(NULL, delim);
	}
	args = realloc(args, sizeof(char *) * (index + 1));
	args[index] = NULL;
	/*free(args);*/
	return (args);
}
