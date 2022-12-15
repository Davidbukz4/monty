#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char *filename;

void free_list(stack_t *head);
void _pall(stack_t **head, unsigned int line_no);
void exec_func(stack_t **head, char *line, unsigned int line_no);
FILE *chk_file(int ac, char **av);
char **_strtow(char *str, char delim);
int _strcmp(char *s1, char *s2);
char *chk_val(char *line);
void _push(stack_t **head, char *line, unsigned int line_no);
stack_t *add_node(stack_t **head, int n);
char *skip_spaces(char *str);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char **sep_str(char *line);


#endif /* MONTY_H */
