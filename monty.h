#ifndef MONTY_H_
#define MONTY_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * struct GlobalStruct - contains all globals
 * @data: int for push
 * @fm: file stream for monty file
 * @lineptr: pointer to char sting allocated by getline function
 */
struct GlobalStruct
{
        FILE *fptr;
        char *lineptr;
} globes;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern int data;
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void arg_check(char **argv);
void file_err(FILE *file, char **argv);
void matcher(instruction_t *match, char *token, stack_t **stack, int line_no);
void malloc_err(void);
bool isNumber(char *string);
void push_err(int lineNumber);
void free_stack(stack_t *stack);
void exit_free(stack_t *stack);
#endif
