#include "monty.h"

void _pall(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	(void) line_no;

	if (!head)
		return;
	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
