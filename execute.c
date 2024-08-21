#include "shell.h"

/**
 * execute_command - Executes a command based on args
 * @args: Array of arguments representing the command and its options
 *
 * Return: 1 on success, 0 to exit shell, or -1 on error
 */
int execute_command(char **args)
{
	if (strcmp(args[0], "cd") == 0)
		return (shell_cd(args));
	if (strcmp(args[0], "exit") == 0)
		return (shell_exit(args));
	if (strcmp(args[0], "env") == 0)
		return (shell_env(args));
	if (strcmp(args[0], "setenv") == 0)
		return (shell_setenv(args));
	if (strcmp(args[0], "unsetenv") == 0)
		return (shell_unsetenv(args));
	return (launch_command(args));
}

/**
 * launch_command - Forks and executes a non-builtin command
 * @args: Array of arguments for the command
 *
 * Return: 1 on success, -1 on error
 */
int launch_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "%s: not found \n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("shell");
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
