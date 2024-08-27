#include "shell.h"
/**
* update_directory - Updates the PWD and OLDPWD environment variables.
*
* Return: 1 on success, -1 on failure.
*/
int update_directory(void)
{
char cwd[PATH_MAX];

if (getcwd(cwd, PATH_MAX) == NULL)
{
perror("getcwd");
return (-1);
}
setenv("PWD", cwd, 1);
setenv("OLDPWD", getenv("PWD"), 1);

return (1);
}

/**
* change_to_home - Changes the directory to the home directory.
* @args: An array of arguments where args[1] is set to the home directory.
*
* Return: 1 on success, -1 on failure.
*/
int change_to_home(char **args)
{
args[1] = getenv("HOME");
if (args[1] == NULL)
{
fprintf(stderr, "shell: expected argument to \"cd\"\n");
return (-1);
}

return (chdir(args[1]));
}

/**
* change_to_oldpwd - Changes the directory to the previous directory.
*
* Return: 1 on success, -1 on failure.
*/
int change_to_oldpwd(void)
{
char *oldpwd = getenv("OLDPWD");

if (oldpwd != NULL)
{
if (chdir(oldpwd) != 0)
{
perror("shell");
return (-1);
}
printf("%s\n", oldpwd);
return (1);
}
else
{
fprintf(stderr, "shell: OLDPWD not set\n");
return (-1);
}
}

/**
* shell_cd - Changes the current directory of the shell.
* @args: An array of arguments, where args[1] is the directory to change to.
*
* Return: 1 on success, -1 on failure.
*/
int shell_cd(char **args)
{
if (args[1] == NULL)
{
if (change_to_home(args) == -1)
return (-1);
}
else if (strcmp(args[1], "-") == 0)
{
if (change_to_oldpwd() == -1)
return (-1);
}
else
{
if (chdir(args[1]) != 0)
{
perror("shell");
return (-1);
}
}

return (update_directory());
}
