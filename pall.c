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
