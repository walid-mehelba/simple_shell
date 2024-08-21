#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100

extern char **environ;

char *_getline(void);
char **_strtok(char *line);
int execute_command(char **args);
void shell_loop(void);
int shell_cd(char **args);
int shell_exit(char **args);
int shell_env(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);
void handle_logical_operators(char **args);
void handle_aliases(char **args);
void replace_variables(char **args);
void handle_file_input(char *filename);
void strip_comments(char *line);
int launch_command(char **args);

#endif
