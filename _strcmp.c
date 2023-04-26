#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: res
 */

int _strcmp(char *s1, char *s2)
{
	int sub;
	int x = 0;

	while (s1[x] == s2[x] && s1[x] != '\0')
	{
		sub = 0;
		x++;
	}
	sub = s1[x] - s2[x];
	return (sub);
}
