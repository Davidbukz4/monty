#include "monty.h"

global_t glo;

/**
 * free_all - frees the stack
 */
void free_all(void)
{
	if (glo.head)
		free_list(glo.head);
	if (glo.buf_line)
		free(glo.buf_line);
	if (glo.fp)
		fclose(glo.fp);
}

FILE *chk_file(int ac, char **av)
{
	FILE *fp;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_all();
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_all();
		exit(EXIT_FAILURE);
	}

	return (fp);
}

/**
 * main - entry point
 * @ac: argument count
 * @av: array of argument strings
 * Return: 0 if successful
 */
int main(int ac, char **av)
{
	unsigned int line_no = 0;
	size_t buf = 0;
	ssize_t file_status;

	glo.fp = chk_file(ac, av);
	file_status = getline(&glo.buf_line, &buf, glo.fp);
	if ((glo.buf_line)[file_status - 1] == '\n')
		(glo.buf_line)[file_status - 1] = '\0';
	while (file_status != -1)
	{
		line_no++;
		if (file_status >= 1)
			exec_func(&glo.head, glo.buf_line, line_no);
		else
			free(glo.buf_line);
		file_status = getline(&glo.buf_line, &buf, glo.fp);
		if ((glo.buf_line)[file_status - 1] == '\n')
			(glo.buf_line)[file_status - 1] = '\0';
	}

	free_all();
	return (0);
}
