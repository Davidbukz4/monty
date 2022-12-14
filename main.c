#include "monty.h"

FILE *chk_file(int ac, char **av)
{
	FILE *fp;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	return (fp);
}

int main(int ac, char **av)
{
	stack_t *head = NULL;
	unsigned int line_no = 0;
	size_t buf = 0;
	ssize_t file_status;
	char *line = NULL;
	FILE *fp;

	fp = chk_file(ac, av);
	file_status = getline(&line, &buf, fp);
	while (file_status != -1)
	{
		line_no++;
		if (file_status >= 1)
			exec_func(&head, line, line_no);
		else
			free(line);
		file_status = getline(&line, &buf, fp);
	}

	fclose(fp);
	exit(EXIT_SUCCESS);
}
