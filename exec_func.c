#include "monty.h"

void exec_func(stack_t **head, char *line, unsigned int line_no)
{
	int i, j;
	/*char **sep_line = NULL;*/
	char **str = NULL;
	instruction_t cmd[] = {
		{"pall", _pall},
		{NULL, NULL}
	};

	/* sep_line = _strtow(line, ' ');*/
	/* str = skip_spaces(line); */
	str = sep_str(line);

	for (j = 0; str[j]; j++)
	{
		if (str[j][0] == '\0')
			continue;
		if (_strncmp("push", str[j], _strlen("push")) == 0)
		{
			printf("j is %s\n", str[j]);
			_push(head, line, line_no);
			return;
		}
		for (i = 0; cmd[i].opcode; i++)
		{
			if (_strncmp(cmd[i].opcode, str[j], _strlen(cmd[i].opcode)) == 0)
			{
				(cmd[i].f)(head, line_no);
				return;
			}
			else
				continue;
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
	exit(EXIT_FAILURE);
}
