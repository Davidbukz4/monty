#include "monty.h"

char **sep_str(char *line)
{
	char **ptr;
	int i = 0, j = 0, cnt = 0, k = 0;

	ptr = (char **)malloc(_strlen(line) * sizeof(ptr));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	ptr[0] = malloc(sizeof(char *));
	if (ptr[0] == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
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
				fprintf(stderr, "Error: malloc failed");
				exit(EXIT_FAILURE);
			}
            j = 0; /* for next word, init index to 0 */
        }
        else {
            ptr[cnt][j] = line[i];
            j++;
        }
    }

	/*for (j = 0; j < _strlen(line); j++)
		free(ptr[j]);
	free(ptr); */

	return (ptr);
}
