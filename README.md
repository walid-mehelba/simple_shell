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
```ruby
$ ls
$ /bin/ls -l
$ setenv MY_VAR HelloWorld
$ echo $MY_VAR
$ unsetenv MY_VAR
$ cd /tmp
$ exit
```
**Installation**:

To compile and use the simple shell, follow these steps:

1. Clone the repository:

```ruby
git clone https://github.com/walid_mehelba/simple_shell.git
```
2. Navigate into the project directory:
```ruby
cd simple_shell
```
3. Compile the source code using GCC:
```ruby
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
4. Run the shell:
```ruby
./hsh
```

**Built-in Commands:**
1. ``exit``: Exit the shell.
2. ``env``: Print the current environment variables.
3. ``setenv VARIABLE VALUE``: Set or modify an environment variable.
4. ``unsetenv VARIABLE``: Remove an environment variable.
5. ``cd [DIRECTORY]``: Change the current directory. If no directory is provided, it changes to the home directory.
6. ``alias``: Define or display aliases.

**Advanced Features:**

Support for Command Line Arguments: Commands can be provided with arguments, and the shell will parse and execute them correctly.
PATH Handling: The shell uses the ``PATH`` environment variable to locate executable files.
Logical Operators: The shell supports the use of ``&&`` and ``||`` for command execution based on the success or failure of previous commands.
Variable Replacement: Supports replacement for special variables like ``$?`` (exit status of the last command) and ``$$`` (process ID of the shell).
Comments: Lines starting with ``#`` are treated as comments and ignored.

**Testing**:

To ensure the shell is working correctly, you can create a test script with different commands and execute it. For example, create a test_script.sh file with the following content:

```ruby
#!/bin/bash
echo "Testing simple shell"
./simple_shell << EOF
ls
setenv MY_VAR Hello
echo $MY_VAR
unsetenv MY_VAR
cd /
pwd
exit
EOF
```
Run the test script:

```
bash test_script.sh
 ```

**Contributors**:

**Walid Mehelba:** Initial version of the simple shell project.

**Laila Mohamed:** Contributions and enhancements to the project.
