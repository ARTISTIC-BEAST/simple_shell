#include "shell.h"

/**
 * free_list - frees a list
 * @head: head of the list
 */

void free_list(p_list *head)
{
	p_list *temp;

	while (head)
	{
		temp = (*head).next;
		free((*head).str);
		free(head);
		head = temp;
	}
	head = NULL;
}

/**
 * free_double - frees a double pointer
 * @ptr: pointer to free
 */

void free_double(char **ptr)
{
	int i;

	if (ptr)
	{
		for (i = 0; ptr[i]; i++)
			free(ptr[i]);
		free(ptr);
	}
}

/**
 * free_single - frees a pointer
 * @ptr: pointer to free
 */

void free_single(char *ptr)
{
	if (ptr)
		free(ptr);
}
