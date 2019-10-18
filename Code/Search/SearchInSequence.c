/*
	���ұ�ĵ�һ��(r[0]) ������
	û���ҵ���ʱ�򷵻�0;

*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAXN 20
#define MAX 1000
#define MIN 1
typedef int KeyType;
typedef int InfoType;
typedef struct node {
	KeyType key;
	InfoType data;//�ڲ��ҹ����в��漰 
}SqList;

int SeqSearch(SqList r[], int n, KeyType key);
int BinSearch(SqList r[], int m, KeyType key);
void randassign(SqList r[], int n);
void printkey(SqList r[], int n);

int main(void)
{
	srand((unsigned int)time(NULL));
	int number;
	SqList r[MAXN+1];

	randassign(r, MAXN);
	printkey(r, MAXN);

	printf("Pls input the number you want to search: ");
	scanf("%d", &number);
	int index = SeqSearch(r, MAXN, number);
	printf("\nThe number is the number: %d\n", index);
	index = BinSearch(r, MAXN, number);
	printf("\nThe number is the number: %d\n", index);
	system("pause");
	return 0;
}


//������������������������������������ 
int SeqSearch(SqList r[], int n, KeyType key)//rec:record����¼�����ݿⳣ�ô� 
{
	int i = 0;
	r[0].key = key;
	for (i = n; r[i].key != key; i--)//ѧϰ���ּ���д�� 
		;/*Empty loop*/
	return i;
}
int BinSearch(SqList r[], int n, KeyType key)//С�ڵ���
{
	int low = 1, high = n, mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (r[mid].key == key)	return mid;
		else if (r[mid].key > key) high = mid - 1;//д���ˣ�����
		else low = mid + 1;
	}
	return 0;
}
void randassign(SqList r[], int n)
{
	for (int i = 1; i <= n; i++)//��һ������
		r[i].key = rand() % MAX + MIN;
}
void printkey(SqList r[], int n)
{
	printf("The records:\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d\t", r[i].key);
		if (i % 5 == 0)
			printf("\n");
	}
	printf("\n");
}
