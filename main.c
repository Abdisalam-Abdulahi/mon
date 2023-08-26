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
	size_t n = 0;
	int line_no = 0;
	char *token1, *token2;
	stack_t *stack = NULL;
	instruction_t match[5] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	arg_check(argv);
	globes.fptr = NULL;
	globes.fptr = fopen(argv[1], "r");
	file_err(globes.fptr, argv);
	globes.lineptr = NULL;
	while (getline(&globes.lineptr, &n, globes.fptr) != -1)
	{
		line_no++;
		token1 = strtok(globes.lineptr, " \n\t\r");
		if (token1 != NULL)
		{
			token2 = strtok(NULL, " \n\t\r");
			if (token2 != NULL && strcmp(token1, "push") == 0)
			{
				if (!isNumber(token2))
					push_err(line_no);
				data = atoi(token2);
			}
			if (token2 == NULL && strcmp(token1, "push") == 0)
				push_err(line_no);
		}
		if (token1 == NULL)
			continue;
		matcher(match, token1, &stack, line_no);
		free(globes.lineptr);
		globes.lineptr = NULL;
	}
	exit_free(stack);
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
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
  *free_stack - frees the stack of double linked list
  *@stack: the top node of the stack
  */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
/**
  *exit_free - frees the stack, close the file,  and exit
  *@stack: the top node of the stack
  */
void exit_free(stack_t *stack)
{
	fclose(globes.fptr);
	if (globes.lineptr != NULL)
		free(globes.lineptr);
	free_stack(stack);
}
