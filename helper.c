#include "monty.h"

/**
 * chk_val - check for any instance of a digit
 * @line: line read from the file
 * Return: digit in string format
 */
char *chk_val(char *line)
{
	char *num = line;

	if (!num)
		return (NULL);
	while (*num && (*num < '0' || *num > '9'))
	{
		++num;
	}
	if (*num == '\0')
		return (NULL);
	return (num);
}


/**
 * sep_str - separate strings into tokens
 * @line: line string read from file
 * Return: pointer to tokenized string
 */
char **sep_str(char *line)
{
	char **ptr;
	int i = 0, j = 0, cnt = 0, k = 0;

	ptr = (char **)malloc(_strlen(line) * sizeof(ptr));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ptr[0] = malloc(sizeof(char *));
	if (ptr[0] == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(ptr);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= (_strlen(line)); i++)
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\0')
		{
			ptr[cnt][j] = '\0';
			cnt++; /* for next word */
			ptr[cnt] = malloc(sizeof(char *));
			if (ptr[cnt] == NULL)
			{
				for (k = 0; k < cnt; k++)
					free(ptr[k]);
				free(ptr);
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			j = 0; /* for next word, init index to 0 */
		}
		else
		{
			ptr[cnt][j] = line[i];
			j++;
		}
	}
	return (ptr);
}


/**
 * get_argument - return the arguments for calulations
 * @head: pointer to dll
 * @line_no: line number
 * Return: the argument
 */
int get_argument(stack_t **head, unsigned int line_no)
{
	int val;
	stack_t *temp;

	if (!head || !(*head))
	{
		printf("L%d: can't add, stack too short\n", line_no);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;

	if (temp == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_no);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	val = temp->n;
	free(temp);
	return (val);
}
