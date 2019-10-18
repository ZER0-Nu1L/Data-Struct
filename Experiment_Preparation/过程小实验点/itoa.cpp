#include<stdio.h>
#include<stdlib.h>
#include<string.h>  

int main(void)
{
	char temp[20];
		for (int i = 0; i < 10; i++)
		{
			char no[10] = "No.";
			itoa(i, temp, 10);
			strcat(no, temp);
			printf("%s\n", no);
		}
	return 0;
}
