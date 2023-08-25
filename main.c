#include "monty.h"
void nothing(void);
int data;
/**
  *main - code driver
  *@argc: argument counter
  *@argv: arguments
  *Return: 0 for sucess
  */
int main(int __attribute__ ((unused)) argc, char *argv[])
{
	char *lineptr;
	size_t n = 0;
	int line_no = 0;
	char *token1, *token2;
	FILE  *fptr;
	stack_t **stack = malloc(sizeof(stack_t));
	instruction_t match[4] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	arg_check(argv);
	malloc_err(stack);
	fptr = fopen(argv[1], "r");
	file_err(fptr, argv);
	while (getline(&lineptr, &n, fptr) != -1)
	{
		line_no++;
		token1 = strtok(lineptr, " \n\t\r");
		if (token1 != NULL)
		{
			token2 = strtok(NULL, " \n\t\r");
			if (token2 != NULL)
			{
				if (!isNumber(token2))
					push_err(line_no);
				data = atoi(token2);
				/*printf("%d\n", data);*/
			}
			if (token2 == NULL && strcmp(token1, "push") == 0)
				push_err(line_no);
		}
		matcher(match, token1, stack, line_no);
	}
	fclose(fptr);

	return (0);
}

/**
  *matcher - matches opcode with its function
  *@match: stracture which contains opcode and function
  *@token: opcode
  *@stack: used for creating double linked list
  *@line_no: line number of the opcode
  */
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
