#include "monty.h"

void _push(stack_t **head, char *line, unsigned int line_no)
{
	char *val = NULL;
	stack_t *node = NULL;
	int iVal = 0;
	unsigned int i = 0;
	char **new_line = NULL;

	/* new_line = _strtow(line, ' '); */
	new_line = sep_str(line);
	for (i = 0; new_line[i]; i++)
	{
		val = chk_val(new_line[i]);
		if (val)
			break;
	}
	if (val == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		free(line);
		free(*head);
		exit(EXIT_FAILURE);
	}
	iVal = atoi(val);
	node = add_node(head, iVal);
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_list(*head);
		exit(EXIT_FAILURE);
	}
}
