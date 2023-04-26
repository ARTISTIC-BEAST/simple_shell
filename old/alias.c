#include "shell.h"

struct alias aliases[MAX_ALIASES];
/**
 * print_aliases: function name
 * Description: prints aliases
 * Return: void
 */

void print_aliases(void)
{
	int num_aliases = 0;

	for (int i = 0; i < num_aliases; i++)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * print_alias - function name
 * Description: prints an alias
 * @name: ptr to name
 * Return: void
 */

void print_alias(char *name)
{
	for (int i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
			return;
		}
	}
	fprintf(stderr, "alias: %s: not found\n", name);
}

/**
 * add_alias - new function
 * Description: adds an alias
 * @name: ptr to alias name
 * @value: ptr to alias value
 * Return: void
 */

void add_alias(char *name, char *value)
{
	for (int i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			strncpy(aliases[i].value, value, MAX_ALIAS_VALUE_LENGTH - 1);
			aliases[i].value[MAX_ALIAS_VALUE_LENGTH - 1] = '\0';
			return;
		}
	}
	if (num_aliases >= MAX_ALIASES)
	{
		fprintf(stderr, "alias: too many aliases\n");
		return;
	}
	strncpy(aliases[num_aliases].name, name, MAX_ALIAS_NAME_LENGTH - 1);
	aliases[num_aliases].name[MAX_ALIAS_NAME_LENGTH - 1] = '\0';
	strncpy(aliases[num_aliases].value, value, MAX_ALIAS_VALUE_LENGTH - 1);
	aliases[num_aliases].value[MAX_ALIAS_VALUE_LENGTH - 1] = '\0';
	num_aliases++;
}

/**
 * process_command - function name
 * Description: processes commands
 * @command: ptr to command
 * Return: void
 */

void process_command(char *command)
{
	char *token;
	char *equals;

	if (token == NULL)
	{
		return;
	}
	if (strcmp(token, "alias") == 0)
	{
		token = strtok(NULL, " ");
		if (token == NULL)
		{
			print_aliases();
			return;
		}
		equals = strchr(token, '=');
		if (equals == NULL)
		{
			print_alias(token);
		}
		else
		{
			*equals = '\0';
			add_alias(token, equals + 1);
		}
	}
	else
	{
		/* handle other commands here*/
	}
}

/**
 * main - entry point
 * Decription: processes commands
 * Return: 0
 */

int main(void)
{
	char *newline;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		char command[100];

		fgets(command, sizeof(command), stdin);
		if (feof(stdin))
		{
			break;
		}
		newline = strchr(command, '\n');
		if (newline != NULL)
		{
			*newline = '\0';
		}
		process_command(command);
	}
	return (0);
}
