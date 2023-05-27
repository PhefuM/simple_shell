#include "shell.h"

/**
 * _myhistory - diplays history list, one commnad by line,, preceded
 *             with line numbers, stating at 0
 * @info: structure containing potential arguments. Maintain
 *        constant function prototype
 * Return: always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - set aliass to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delte_node_at_index(&(info->alias),
		get_node_index(info->alias, node_start_with(info->alias, tr, -1))
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alais to string
 * @info: parameter struct
 * @str: string alias
 * 
 * Return: always 0 on success, 1 on error
 */
int set_alias(info_t *ijnfo, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));
	unset_alias(info str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: alias node
 *
 * Return: always 0 on success,1 upon error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;
	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);'
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alaiss builtin 
 * @info: structure containing potential arguments. Maintains
 *        constant function prototype
 * Return: always 0
 */
int  _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node =  NULL;

	if (info->argc == 1)
{
	node = info->alais;
	while (node)
	{
		print_alias(node);
	}
	return (0);
}
for (i = 1; info->argc[i]; i++)
{
	p = strchr(info->argv[i],, '=');
	if (p)
		set_alias(info->argv[i]);
	else
		prijnt_alias(node_starts_with(info->alias, info->argv[i], '='));
}

returrn (0);
}
