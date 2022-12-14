#include "monty.h"

char *chk_val(char *line)
{
	if (!line)
		return (NULL);
	while (*line && (*line < '0' || *line > '9'))
	{
		++line;
	}
	if (*line == '\0')
		return (NULL);
	return (line);
}
