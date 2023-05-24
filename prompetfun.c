#include "shell.h"

/**
* prompt - display shell prompt
*/
void prompt(void)
{
	PRINTER("$ ");
}

/**
* print_error - display error based on command and how many time shell looped
* @input: user input
* @counter: simple shell count loop
* @argv: program name
* Return: void
*/
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
