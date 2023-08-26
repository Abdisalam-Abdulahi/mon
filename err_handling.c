#include "monty.h"
/**
  *arg_check - checks if there is file to open
  *@argv: the file to be checked its existance
  */
void arg_check(char **argv)
{
	if (argv[1] == NULL || argv[2] != NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
  *file_err - checks if ther is error in openning the file
  *@file: the file to be checked
  *@argv: the file to be checked
  */
void file_err(FILE *file, char **argv)
{
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}
/**
  *malloc_err - checks if malloc is returning error or not
  *@ptr: the pointer to be checked
  */
void malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
/**
  *push_err - prints error when push has not argument or
  *it has non integer argument
  *@line_no: error line
  */
void push_err(int line_no)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_no);
	exit(EXIT_FAILURE);
}
