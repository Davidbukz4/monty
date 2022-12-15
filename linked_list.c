#include "monty.h"

/**
 * add_node - adds node to the top of a list
 * @head: pointer to the head node
 * @n: node value
 * Return: pointer to head node
 */
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


/**
 * free_list - frees a linked list
 * @head: pointer to head node
 * Return: void
 */
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
