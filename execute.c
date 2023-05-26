#include "shell.h"
#include <sys/wait.h>

/**
 * handle_builtin - Handle the builtin command
 * @cmd: The parsed command
 * @er: Statue of last execute
 * Return: -1 Fail, 0 upon Success
 */

int handle_builtin(char **cmd, int er)
{
	typedef struct
	{
		char *command;
		int (*fun)(char **cmd, int er);
	} bul_t;

	bul_t bil[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL},
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * check_cmd - Execute Simple Shell Command (fork,wait,execute)
 *
 * @cmd: Parsed Command
 * @input: User input
 * @c: Shell execution time case of command not found
 * @argv: Program name
 * Return: 1 Case command NULL, -1 wrong command 0 command executed
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_handle - Handle ^C
 * @sig: The captured signal
 * Return: Void
 */
void signal_to_handle(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$");
	}
}
