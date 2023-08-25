#include "monty.h"
/**
  *pall - print stack from top
  *@stack: top of the stack
  *@line_number: line number
  */
void pall(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		return;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
