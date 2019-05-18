#include<stdio.h> 
#include<stdlib.h>

int main(int argc, char* argv[])
{
	FILE* fp1, *fp2;//Ö¸Õë 1111111111111111
	fp1 = NULL;
	
	if(argc != 3)
	{
		printf("Error parameter\n");
		exit(EXIT_FAILURE);
	}
	if((fp1 = fopen(argv[1], "rb"))==NULL)
	{
		fprintf(stderr,"%s can't open!\n", argv[1]);//22222222222222wr Ð´Çå³þ 
		//printf("%s can't open!\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if((fp2 = fopen(argv[2], "wb"))==NULL)
	{/////////////////
		printf("%s can't open!\n", argv[2]);
		printf("Then we create one for you!\n");
		fp2 = fopen(argv[2], "wb");
	}
	
	char c;
	while( (c = fgetc(fp1) )!= EOF)
	{
		fputc(c, fp2);
		putchar(c);
	}
	
	printf("Success!\n");
	printf("%d\n", EOF);
	
	fclose(fp1);fclose(fp2);
	
	return 0;
}
