#include "monty.h"
/**
  *push - addes new node on the top of the list
  *@stack: top node
  *@line_number: line_number
  */
void push(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	        stack_t *tmp;

        tmp = malloc(sizeof(stack_t)); /* not freed */
        if (tmp == NULL)
        {
                fprintf(stderr, "Error: malloc failed");
                exit_free(*stack);
                exit(EXIT_FAILURE);
        }
        tmp->n = data;
        tmp->prev = NULL;
        tmp->next = NULL;
        if (*stack != NULL)
        {
                tmp->next = *stack;
                (*stack)->prev = tmp;
        }
        *stack = tmp;
/*	stack_t *temp = malloc(sizeof(stack_t));
	
	if (temp == NULL)
		malloc_err();
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
	}*/
}
/**
  *isNumber - checks if string is number
  *@string: the string to be checked
  *Return: True or False
  */
bool isNumber(char *string)
{
	int i = 0;

	for (i = 0; string[i] != '\000'; i++)
	{
		if (isdigit(string[i]) == 0)
			return (false);
	}
	return (true);
}
