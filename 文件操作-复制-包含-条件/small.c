#include<stdio.h>
#include<stdlib.h>
#define A 0
#define B 1//0
#define FILE_NAME "data"

int main(void)
{
	FILE* fp = NULL;
	fp = fopen(FILE_NAME,"wb+");
	fprintf(fp, "You are successful!\n");
	fclose(fp);
	
#ifdef A
	printf("This is how ifdef work!\n");
#endif
#if B
	printf("Ha??\n");
#endif
	return 0;
}
