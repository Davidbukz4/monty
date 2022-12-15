#include "monty.h"

/**
 * exec_func - executes command from the file
 * @head: pointer to head node of doubly linked list
 * @line: line read from file
 * @line_no: line number of the line :)
 * Return: void
 */
void exec_func(stack_t **head, char *line, unsigned int line_no)
{
	int i, j;
	char **str = NULL, **new_str = NULL;
	instruction_t cmd[] = {
		{"pall", _pall},
		{NULL, NULL}
	};

	str = sep_str(line);
	for (j = 0; str[j]; j++)
	{
		if (str[j][0] == '\0')
		{
			new_str = _strtow(line, ' ');
			if (new_str)
				str[j] = new_str[0];
			else
				return;
		}
		if (_strcmp("push", str[j]) == 0)
		{
			_push(head, line, line_no);
			return;
		}
		for (i = 0; cmd[i].opcode; i++)
		{
			if (_strcmp(cmd[i].opcode, str[j]) == 0)
			{
				(cmd[i].f)(head, line_no);
				return;
			}
		}
	}
	for (i = 0; str[i]; i++)
		if (str[i][0] != '\0')
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_no, str[i]);
			break;
		}
	free(line);
	free_list(*head);
	*head = NULL;
	exit(EXIT_FAILURE);
}
