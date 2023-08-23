#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int __attribute__ ((unused)) argc, char *argv[])
{
	FILE  *fptr;
	char str[1000];
	int i = 0;
	int j = 0;
	char **arr = malloc(sizeof(str));;
	
	fptr = fopen(argv[1], "r");
	while(fgets(str, 1000, fptr))
	{
		arr[i] = malloc(strlen(str) + 1);
		strcpy(arr[i], str);
		printf("%s", str);
		i++;
	}
	printf("len is %d\n", i);
	printf(" this is what %s", arr[2]);
	fclose(fptr);

	 for (j = 0; j < i; j++) 
	 {
        	free(arr[j]);
    	 }
    	free(arr);

	return (0);
}
