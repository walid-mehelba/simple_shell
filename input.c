#include "shell.h"

/**
 * _getline - Reads a line of input from stdin
 *
 * Return: Pointer to the input string
 */
char *_getline(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}

/**
 * _strtok - Splits a string into tokens based on delimiters
 * @line: The string to be tokenized
 *
 * Return: Array of tokens (command and arguments)
 */
char **_strtok(char *line)
{
	int bufsize = MAX_ARGS, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
		exit(EXIT_FAILURE);
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position++] = token;
		if (position >= bufsize)
		{
			bufsize += MAX_ARGS;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
				exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
