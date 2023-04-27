#include "shell.h"
/**
 * tokenize - this function separate the string using a designed delimiter
 * @data: a pointer to the program's data
 * Return: an array of the different parts of the string
 */
void tokenize(data_of_program *data)
{
	char *delimiter = " \t";
	int j, k, counter = 2, length;

	length = str_length(data->input_line);
	if (length)
	{
		if (data->input_line[length - 1] == '\n')
			data->input_line[length - 1] = '\0';
	}

	for (j = 0; data->input_line[j]; j++)
	{
		for (k = 0; delimiter[k]; k++)
		{
			if (data->input_line[j] == delimiter[k])
				counter++;
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	j = 0;
	data->tokens[j] = str_duplicate(_strtok(data->input_line, delimiter));
	data->command_name = str_duplicate(data->tokens[0]);
	while (data->tokens[j++])
	{
		data->tokens[j] = str_duplicate(_strtok(NULL, delimiter));
	}
}
