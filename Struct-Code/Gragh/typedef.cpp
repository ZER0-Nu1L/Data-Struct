#include<stdio.h>

int main(void)
{
	typedef int INT_ARRAY_100[100];
	INT_ARRAY_100 arr;
	arr[1]=0;
	for(int i = 0; i < 100; i++)
	{
		arr[i]=i;
		printf("%d ",arr[i]);
	}
	return 0;
}