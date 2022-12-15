#include "monty.h"

/**
 * _strtow - function that splits a string into words.
 * @str: string to split
 * @delim: character where string is to be splitted
 * Return: pointer to array of splitted string separated by delimiter
 */
char **_strtow(char *str, char delim)
{
	char *w;
	char **s;
	int i = 0, j = 0, k, words = 0, len = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	while (str[i])
	{
		if (str[i] == delim && str[i - 1] && str[i - 1] != delim)
			words++;
		i++;
	}
	if (str[i] == '\0' && str[i - 1] && str[i - 1] != delim)
		words++;
	if (words == 0)
		return (NULL);
	s = (char **) malloc(sizeof(char *) *  (words + 1));
	if (s == NULL)
		return (NULL);
	words = 0, len = i;
	for (i = 0; i <= len; i++)
	{
		if ((str[i] == delim && str[i - 1] && str[i - 1] != delim)
			|| (str[i] == '\0' && str[i - 1] && str[i - 1] != delim))
		{
			w = (char *) malloc(sizeof(char) * (j + 1));
			if (w == NULL)
				return (NULL);
			s[words] = w;
			words++;
			for (k = 0; k < j; k++)
				w[k] = str[i -  j + k];
			w[k] = '\0';
			j = 0;
		}
		else if (str[i] != delim)
			j++;
	}
	s[words] = NULL;
	return (s);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: integer than is greater, lesser, or equal to zero depending
 * on string comparison
 */
int _strcmp(char *s1, char *s2)
{
	int x, y, z, comparison;

	x = y = comparison = 0;

	while (s1[x] != '\0')
		x++;
	while (s2[y] != '\0')
		y++;

	for (z = 0; z < x; z++)
	{
		if (s1[z] != s2[z])
		{
			comparison = s1[z] - s2[z];
			break;
		}
		else if (s1[z] == s2[z])
		{
			comparison = s1[z] - s2[z];
			continue;
		}
	}

	return (comparison);
}


/**
 * skip_spaces - skip whitespaces
 * @str: a string
 *
 * Return: pointer to where is the first non space char or NULL
 */
char *skip_spaces(char *str)
{
	if (!str)
		return (NULL);

	while (*str && *str == ' ')
		++str;
	if (*str == '\0') /*empty string*/
		return (NULL);

	return (str);
}

/**
 * _strlen - string length
 * @s: string
 * Return: length of string
 */
int _strlen(char *s)
{
	int x = 0;

	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}


/**
 * _strncmp - compare 2 strings see strcmp()
 * @s1: string to compare
 * @s2: opcode
 * @n: length of opcode to compare
 * Return: It returns 0 if OK
*/
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0' && i < n)
	{
		if (*(s1 + i) == *(s2 + i))
		{
			++i;
		}
		else
		{
			return (*(s1 + i) - *(s2 + i));
		}
	}
	if (i == n && (*(s1 + i) == ' ' || *(s1 + i) == '\t' ||
		       *(s1 + i) == '\0' || *(s1 + i) == '\n'))
		return (0);
	return (EXIT_FAILURE); /* one of the strings was too short, not the best*/
}
