#include "monty.h"

int data;
int main(int __attribute__ ((unused)) argc, char *argv[])
{
	char *lineptr;
	size_t n = 0;
	int line_no = 0;
	int i;
	char *token1, *token2;
	FILE  *fptr;
	stack_t **stack = malloc(sizeof(stack_t));
	stack_t *top = malloc(sizeof(stack_t));
	fptr = fopen(argv[1], "r");
	instruction_t match[3] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	while(getline(&lineptr, &n, fptr) != -1)
	{
		line_no++;
		token1 = strtok(lineptr, " \n\t\r");
		if (token1 != NULL)
		{
			token2 = strtok(NULL, " \n\t\r");
			if (token2 != NULL)
			{
				data = atoi(token2);
				/*printf("%d\n", data);*/
			}
		}
		i = 0;
		while (match[i].opcode)
		{
			if (strcmp(match[i].opcode, token1) == 0)
			{
				match[i].f(stack, line_no);
				break;
			}
			i++;
		}
/*				
		if (strcmp("push", token1) == 0)
			push(stack, line_no);
		printf("%s\n", token1);
		if (strcmp("pall", token1) == 0)
			pall(stack, line_no);*/
	}
	fclose(fptr);

	return (0);
}
/*
char **tokenize(char **arr, int i)
{
	int k;
	char *token;
	for (k = 0; k < i; k++)
	{
		arr[k] = strtok(arr[k], " \t\r\n");
		if (strcmp("push", arr[k]) == 0)
		{
			token = strtok(NULL, " \t\r\n");
			strcat(arr[k], token);
		}
	printf("this %s", arr[k]);
	}
	return (arr);
}*/

