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
/**
  *pop - remove top element of the stack
  *@stack: top element
  *@line_number: line number
  */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		(*stack)->next->prev = NULL;
	}
	*stack = (*stack)->next;
	free(temp);
}
/**
  *nop - remove top element of the stack
  *@stack: top element
  *@line_number: line number
  */
void nop(__attribute__ ((unused)) stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
}








