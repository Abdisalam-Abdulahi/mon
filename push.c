#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = malloc(sizeof(stack_t));
    temp->n = data;
    if (*stack == NULL) 
    {
	    temp->next = NULL;
	    temp->prev = NULL;
	    (*stack) = temp;
    }
    else 
    {
	    (*stack)->next = temp;
	    temp->prev = *stack;
	    *stack = temp;
    }
}
