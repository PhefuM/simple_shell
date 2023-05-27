#include "shell.h"

/**
 * interative -returns  true if shell is interactive mode
 * @info struct address
 *
 * Return : 1 if intermode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isattty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check if the character isa delimeter
 * @c: the char to check
 * @delim: the  delimeter strirng
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char * delim)
{
	while (*delim)
		if (*delim++ == c)
			(return (1);
	retun (0)
}

/**
 * _isapha - chexk for alphabetic charter
 * @c: The charter to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalapha(int c)

{

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= ' Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts the string to an integer
 * @s: string to be converted
 * Return:0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
		flag = 2;
	}
	else if (flag == 1)
		flag = 2;
}

if (sign == -1)
	output = -result;
else
	output = result;
return (output);
}
