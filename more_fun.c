#include "shell.h"
/**
 * _strcpy - Function copies cource to destination char
 * @dest: the destination
 * @src: source
 * Return: Copy of char *
 */
char *_strcpy(char *dest, char *src)
{
int i;

i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
dest[i] = '\0';
return (dest);
}
/**
 * strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: the first and second string char *
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strchr - Function locates char in strijng
 * @s: String source
 * @c: Char to search for
 * Return
 */
char *_strchr(char *s, char c)
{

	do		{
		if (*s == c)
			{
			break;
			}
		}	while (*s++);
return (s);
}
/**
 * _strncmp - Compare number of characters in two strings
 * @s1: String
 * @s1 String
 * @n: Number of of characters to compare
 *
 * Return: 1, otherwise - 0 if strings dont match
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[1])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strdup - Function duplicates a string
 * @str: string
 * Return: NULL - duplicate string failed
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}



