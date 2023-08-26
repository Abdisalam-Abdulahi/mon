#include "monty.h"
/**
  *pint - print top element of the stack
  *@stack: top element
  *@line_number: line number
  */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
