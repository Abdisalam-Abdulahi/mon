#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
     stack_t *temp = *stack;
    if (temp==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
     while(temp!= NULL)
    {
        printf("%d\n",temp->n);
        temp = temp->prev;
    }
}
