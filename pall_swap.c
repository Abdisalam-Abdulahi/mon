#include "monty.h"
/**
  *pall - print stack from top
  *@stack: top of the stack
  *@line_number: line number
  */
void pall(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
  *swap - swap two top nodes of the stack
  *@stack: top of the stack
  *@line_number: line number
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
/*	printf("%d\n", ptr->next->n);*/
	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}
