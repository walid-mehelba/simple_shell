**Simple Shell Project**

**Introduction:**
This project is a simple UNIX command-line interpreter, also known as a shell. It is a basic version of a Unix shell that reads commands from standard input, executes them, and returns the output. The project is written in C and adheres to the Betty coding style. The primary function of this shell is to execute commands provided by the user and handle basic shell functionalities.

**Features:**
Display a prompt and wait for the user to type a command.
Execute commands with and without arguments.
Handle the PATH environment variable to locate executable programs.
Implement built-in commands such as exit, env, setenv, unsetenv, and cd.
Provide basic error handling and manage the "end of file" condition (Ctrl+D).
Supports chaining commands using ; and logical operators && and ||.
Handle variable replacement for $?, $$, and environment variables.
Supports command aliasing.
Handles comments using #.

**Example Commands:**
$ ls
$ /bin/ls -l
$ setenv MY_VAR HelloWorld
$ echo $MY_VAR
$ unsetenv MY_VAR
$ cd /tmp
$ exit

**Built-in Commands:**
exit: Exit the shell.
env: Print the current environment variables.
setenv VARIABLE VALUE: Set or modify an environment variable.
unsetenv VARIABLE: Remove an environment variable.
cd [DIRECTORY]: Change the current directory. If no directory is provided, it changes to the home directory.
alias: Define or display aliases.

**Advanced Features:**
Support for Command Line Arguments: Commands can be provided with arguments, and the shell will parse and execute them correctly.
PATH Handling: The shell uses the PATH environment variable to locate executable files.
Logical Operators: The shell supports the use of && and || for command execution based on the success or failure of previous commands.
Variable Replacement: Supports replacement for special variables like $? (exit status of the last command) and $$ (process ID of the shell).
Comments: Lines starting with # are treated as comments and ignored.

**Contributors**:
**Walid Mehelba:** Initial version of the simple shell project.
**Laila Mohamed:** Contributions and enhancements to the project.
