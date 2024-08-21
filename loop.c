#include "shell.h"

/**
 * shell_loop - Main loop of the shell
 * Continuously reads input, parses it, and executes commands
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int status = 1;

	do {
		printf("$ ");
		line = _getline();
		strip_comments(line);
		args = _strtok(line);
		if (args[0] != NULL)
		{
			replace_variables(args);
			handle_aliases(args);
			handle_logical_operators(args);
			status = execute_command(args);
		}
		free(line);
		free(args);
	} while (status);
}
