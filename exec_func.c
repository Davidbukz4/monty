#include "monty.h"

void exec_func(stack_t **head, char *line, unsigned int line_no)
{
	int i;
	char **sep_line = NULL;
	instruction_t cmd[] = {
		{"pall", _pall},
		{NULL, NULL}
	};

	sep_line = _strtow(line, ' ');
	if (_strcmp("push", sep_line[0]) == 0)
	{
		_push(head, line, line_no);
		return;
	}
	for (i = 0; cmd[i].opcode; i++)
	{
		if (_strcmp(cmd[i].opcode, sep_line[0]) == 0)
		{
			(cmd[i].f)(head, line_no);
			return;
		}
	}
	printf("L%d: unknown instruction %s\n", line_no, sep_line[0]);
	free(line);
	free_list(*head);
	exit(EXIT_FAILURE);
}
