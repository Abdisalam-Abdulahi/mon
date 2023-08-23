#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int __attribute__ ((unused)) argc, char *argv[])
{
	FILE  *fptr;
	char str[100];

	
	fptr = fopen(argv[1], "r");
	while(fgets(str, 100, fptr))
	{
		printf("%s", str);
	}
	fclose(fptr);
	return (0);
}
