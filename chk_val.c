#include "monty.h"

char *chk_val(char *line)
{
	char *num = line;
	if (!num)
		return (NULL);
	while (*num && (*num < '0' || *num > '9'))
	{
		++num;
	}
	if (*num == '\0')
		return (NULL);
	return (num);
}
