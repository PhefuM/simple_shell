#include "shell.h"
/**
 * read_file - Read command from file
 * @filename: Filename
 * @argv: Program name
 * Return: -1 or otherwise 0
 */

void read_file(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	int counter = 0;
	size_t len = 0;

	*fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		treat_file(line, counter, fp, argv);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * treat_file - Parse check command, fork, wait, execute in line of the file
 * @line: check a line from a file
 * @counter: error counter
 * @fp: The file descriptor
 * @argv: The program name
 * Return: execute a line void
 */
void treat_file(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse_cmd(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			exit_bul_for_file(cmd, line, fp);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, st);
			free(cmd);
		}
		else
		{
			st = check_cmd(cmd, line, counter, argv);
			free(cmd);
		}
}
/**
 * exit_bul_for_file - Function exits shell of case of file
 * @line: The line from a file
 * @cmd: Parsed command
 * @fd: The file descriptor
 *
 * Return: Case of exit in a file line
 */
void exit_bul_for_file(char **cmd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(statue);



}
