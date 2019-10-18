#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
#include"readline.h"
#define A 0
#define B 1//0
#define FILE_NAME "data"
using namespace std;
int main(void)
{
	FILE* fp = NULL;
	fp = fopen(FILE_NAME,"wb+");
	fprintf(fp, "You are successful!\n");
	fclose(fp);
//	LinkStNode *a;
//	InitStack(a);
	char str[12];
	readline(str, 5);
#ifdef A
	printf("This is how ifdef work!\n");
#endif
#if B
	printf("Ha??\n");
#endif
	return 0;
}
