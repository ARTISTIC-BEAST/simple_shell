#include "shell.h"


/**
 * itos - converts int to string
 * @counter: integer to convert
 * Return: string of counter
 */

char *itos(unsigned int counter)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = counter;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; counter; --digits)
	{
		numstr[digits] = (counter % 10) + '0';
		counter /= 10;
	}
	return (numstr);
}
