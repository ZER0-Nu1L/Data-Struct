/*ADT Queue
{
	data object:
		D = {a[i]|1<=i<=n, n>0, the type of a[i] is ElemType}
	data relation:
		R = {<a[i], a[i+1]>| a[i], a[i+1] belongs to D, i = 1, 2, 3°≠°≠}
	fundamental operation:
		InitQueue(&q);DestroyQueue(&q);
		QueueIsEmpty(q);
		deQueue(&q, &e);enQueue(&q, e);
		À≥–Ú∂”¡–
}*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#define MAX 100
typedef int ElemType;
typedef struct {
	ElemType data[MAX];
	int front, rare;
}SqQueue;
//-----------------------------------------------------------------
//Create 
void InitQueue(SqQueue *&q);
void DestroyQueue(SqQueue *&q);
//attributes
bool QueueIsEmpty(SqQueue *q);
//Operation on elements
bool deQueue(SqQueue *&q, ElemType &e);
bool enQueue(SqQueue *&q, ElemType e);


//int main(void)
//{
//	int e = 0;
//	SqQueue *q = NULL;
//	InitQueue(q);
//
//	printf("%d %d\n", e, deQueue(q, e));
//	enQueue(q, 12);
//	printf("%d %d\n", e, deQueue(q, e));
//
//	printf("%d\n\n", QueueIsEmpty(q));
//	enQueue(q, 1);
//	enQueue(q, 2);
//	enQueue(q, 3);
//	printf("%d %d\n", e, deQueue(q, e));printf("%d %d\n", e, deQueue(q, e));printf("%d %d\n", e, deQueue(q, e));
//
//	DestroyQueue(q);
//	system("pause");
//	return 0;
//}

//-----------------------------------------------------------------
//Create 
void InitQueue(SqQueue *&q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	if (q == NULL) { printf("Error in malloc!\n"); exit(EXIT_FAILURE); }
	q->front = q->rare = -1;
}
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
//attributes
bool QueueIsEmpty(SqQueue *q)
{
	return (q->front == q->rare);
}
//Operation on elements
bool deQueue(SqQueue *&q, ElemType &e)
{
	if (QueueIsEmpty(q))
		return false;
	else
	{	q->front++;
		e = q->data[q->front];
		return true;
	}
}
bool enQueue(SqQueue *&q, ElemType e)
{
	if (q->rare == MAX-1)
		return false;
	else
	{
		q->rare++;
		q->data[q->rare] = e;
		return true;
	}
}