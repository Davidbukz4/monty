#include "monty.h"

void free_list(stack_t *head)
{
	stack_t *temp;

	if (!head)
		return;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
