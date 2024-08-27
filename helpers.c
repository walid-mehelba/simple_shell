#include "shell.h"

/**
* handle_logical_operators - Processes logical operators (&&, ||) in commands
* @args: Array of arguments, including logical operators
*/
void handle_logical_operators(char **args)
{
	int i = 0, status = 1;
	char *cmds[2];

	while (args[i] != NULL)
	{
		if (strcmp(args[i], "&&") == 0 || strcmp(args[i], "||") == 0)
		{
			args[i] = NULL;
			cmds[0] = args[0];
			cmds[1] = args[i + 1];
			status = execute_command(_strtok(cmds[0]));
			if ((strcmp(args[i], "&&") == 0 && status == 1) ||
				(strcmp(args[i], "||") == 0 && status == 0))
				status = execute_command(_strtok(cmds[1]));
			break;
		}
		i++;
	}
}

/**
* handle_aliases - Handles alias creation and substitution
* @args: Array of arguments
*/
void handle_aliases(char **args)
{

(void)args;
}

/**
* replace_variables - Replaces shell variables like $$ and $?
* @args: Array of arguments, possibly containing variables
*/
void replace_variables(char **args)
{
int i = 0;
char *pid_str, *status_str, *env_var;

while (args[i] != NULL)
{
if (strcmp(args[i], "$$") == 0)
{
pid_str = malloc(12);
sprintf(pid_str, "%d", getpid());
args[i] = pid_str;
}
else if (strcmp(args[i], "$?") == 0)
{
status_str = malloc(12);
if (status_str != NULL)
{
sprintf(status_str, "%d", WEXITSTATUS(errno));
args[i] = status_str;
}
}
else if (args[i][0] == '$' && strlen(args[i]) > 1)
{
env_var = getenv(args[i] + 1);
if (env_var != NULL)
{
args[i] = strdup(env_var);
}
}
i++;
}
}
/**
* handle_file_input - Reads and executes commands from a file
* @filename: The name of the file to read
*/
void handle_file_input(char *filename)
{
	FILE *file = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	char **args;


	if (!file)
	{
		perror("shell");
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		strip_comments(line);

		args = _strtok(line);

		if (args[0] != NULL)
		{
			replace_variables(args);
			handle_aliases(args);
			handle_logical_operators(args);
			execute_command(args);
		}
		free(args);
	}
	free(line);
	fclose(file);
}

/**
* strip_comments - Removes comments from a line of input
* @line: The input string
*/
void strip_comments(char *line)
{
	char *comment_start = strchr(line, '#');

	if (comment_start != NULL)
		*comment_start = '\0';
}
