#include<stdio.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
	
	return 0;
}

bool check_null(void)
{
	FILE*fp = NULL;
	bool flag = true;
	if((fp = fopen(FILE_NAME, "r")) == NULL)
	{
		printf("The file isn't exits!\nNow we create one for you.\n'");
		fp = fopen(FILE_NAME, "w");
		fclose(fp);flag = false;
	}
	return flag;
}
