#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	if (argc == 2)
		handle_file_input(argv[1]);
	else
		shell_loop();
	return (0);
}
