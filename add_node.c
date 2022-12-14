#include "monty.h"

stack_t *add_node(stack_t **head, int n)
{
	stack_t *newnode;

	newnode = (stack_t *)malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		free(newnode);
		return (NULL);
	}
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->n = n;
	if (*head == NULL)
		*head = newnode;
	else
	{
		(*head)->prev = newnode;
		newnode->next = *head;
		*head = newnode;
	}
	return (*head);
}
