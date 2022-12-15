#include "monty.h"

/**
 * _add - add the top 2 values on the stack
 * @head: pointer to head node
 * @line_no: line number
 */
void _add(stack_t **head, unsigned int line_no)
{
	int num1, num2;

	num1 = get_argument(head, line_no);
	num2 = get_argument(head, line_no);

	add_node(head, num1 + num2);
}


/**
 * _nop - do not do anything
 * @head: pointer to head node
 * @line_no: line number
 */
void _nop(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;
}
