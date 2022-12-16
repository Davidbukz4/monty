#include "monty.h"


/**
 * _push - pushes an element to the stack
 * @head: pointer to head node
 * @line: line read from the file
 * @line_no: line number of line :)
 * Return: void
 */
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
		free_list(*head);
		free_all();
		exit(EXIT_FAILURE);
	}
	iVal = atoi(val);
	node = add_node(head, iVal);
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*head);
		free_all();
		exit(EXIT_FAILURE);
	}
}


/**
 * _pall - prints all the value on the stack
 * @head: pointer to head node
 * @line_no: line number of line :)
 * Return: void
 */
void _pall(stack_t **head, unsigned int line_no)
{
	stack_t *temp;

	temp = *head;
	if (*head && line_no)
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}


/**
  * _pint - prints the value at the top of the stack
  * @head: pointer to head node
  * @line_no: line number
  * Return: void pointer
  */
void _pint(stack_t **head, unsigned int line_no)
{
	if (head && *head)
		printf("%d\n", (*head)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		free_all();
		exit(EXIT_FAILURE);
	}
}


/**
 * _pop - pull an element from the stack or queue
 * @head: pointer to head node
 * @line_no: line number
 */
void _pop(stack_t **head, unsigned int line_no)
{
	stack_t *temp = NULL;

	if (!head || !(*head))
	{
		printf("L%d: can't pop an empty stack\n", line_no);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(temp);
}


/**
 * _swap - swap the values of the top and last elements
 * @head: pointer to head node
 * @line_no: line number
 */
void _swap(stack_t **head, unsigned int line_no)
{
	int old_value;

	if (!head || !*head)
	{
		printf("L%d: can't swap, stack too short\n", line_no);
		free_all();
		exit(EXIT_FAILURE);
	}

	old_value = (*head)->n;

	if ((*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_no);
		free_all();
		exit(EXIT_FAILURE);
	}

	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = old_value;
}
