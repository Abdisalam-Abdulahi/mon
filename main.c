#include "monty.h"

int data;
int main(int __attribute__ ((unused)) argc, char *argv[])
{
	arg_check(argv);
	char *lineptr;
	size_t n = 0;
	int line_no = 0;
	int i;
	char *token1, *token2;
	FILE  *fptr;
	stack_t **stack = malloc(sizeof(stack_t));
	malloc_err(stack);
	fptr = fopen(argv[1], "r");
	file_err(fptr, argv);
	instruction_t match[3] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	while(getline(&lineptr, &n, fptr) != -1)
	{
		line_no++;
		token1 = strtok(lineptr, " \n\t\r");
		if (token1 != NULL)
		{
			token2 = strtok(NULL, " \n\t\r");
			if (token2 != NULL)
			{
				data = atoi(token2);
				/*printf("%d\n", data);*/
			}
		}
		matcher(match, token1, stack, line_no);
	}
	fclose(fptr);

	return (0);
}


void matcher(instruction_t *match, char *token, stack_t **stack, int line_no)
{
	int i = 0;
	while (match[i].opcode)
	{
		if (strcmp(match[i].opcode, token) == 0)
		{
			match[i].f(stack, line_no);
			break;
		}
		i++;
	}
	if (match[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, token);
		exit(EXIT_FAILURE);
	}
}
