#include "monty.h"

void _push(stack_t **head, char *line, unsigned int line_no)
{
	char *val = NULL;
	stack_t *node = NULL;
	int iVal = 0;
	char **new_line = NULL;

	new_line = _strtow(line, ' ');
	val = chk_val(new_line[1]);/* code this function */
	if (val == NULL)
	{
		printf("L%d: usage: push integer\n", line_no);
		free(line);
		free(*head);
		*head = NULL;
		exit(EXIT_FAILURE);
	}
	iVal = atoi(val);
	node = add_node(head, iVal);
	if (node == NULL)
	{
		printf("Error: malloc failed");
		free(*head);
		exit(EXIT_FAILURE);
	}
}
