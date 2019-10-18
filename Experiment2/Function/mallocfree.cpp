#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define MALLOC 1
#define MALLOC 1
int main(void) 
{
#if MALLOC
	char *str = (char*)malloc(sizeof(char)*strlen("1234567890"));
	strcpy(str, "1234567890");
	char *str2 = str;
	printf("%s\n", str2);
	free(str);
	
	printf("%s", str2);
#endif

	printf("%d", isspace('\0'));
	return 0;
}

