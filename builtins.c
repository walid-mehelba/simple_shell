#include "shell.h"
#include <limits.h>

/**
* shell_exit - Exits the shell
* @args: Array of arguments (not used)
*
* Return: 0 to indicate shell should exit
*/
int shell_exit(char **args)
{
(void)args;
return (0);
}

/**
* shell_env - Prints the environment variables
* @args: Array of arguments (not used)
*
* Return: 1 on success
*/
int shell_env(char **args)
{
int i = 0;

(void)args;
while (environ[i])
{
printf("%s\n", environ[i]);
i++;
}
return (1);
}

/**
* shell_setenv - Sets or modifies an environment variable
* @args: Array of arguments, with args[1] as the variable name
* and args[2] as the value
*
* Return: 1 on success, -1 on failure
*/
int shell_setenv(char **args)
{
if (args[1] == NULL || args[2] == NULL)
{
fprintf(stderr, "shell: expected argument to \"setenv\"\n");
return (-1);
}
if (setenv(args[1], args[2], 1) != 0)
{
perror("shell");
return (-1);
}
return (1);
}

/**
* shell_unsetenv - Unsets an environment variable
* @args: Array of arguments, with args[1] as the variable name
*
* Return: 1 on success, -1 on failure
*/
int shell_unsetenv(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "shell: expected argument to \"unsetenv\"\n");
return (-1);
}
if (unsetenv(args[1]) != 0)
{
perror("shell");
return (-1);
}
return (1);
}
