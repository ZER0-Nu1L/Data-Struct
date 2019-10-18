/*ADT Queue
{
	data object:
		D = {a[i]|1<=i<=n, n>0, the type of a[i] is ElemType}
	data relation:
		R = {<a[i], a[i+1]>| a[i], a[i+1] belongs to D, i = 1, 2, 3……}
	fundamental operation:
		InitQueue(&q);DestroyQueue(&q);
		QueueIsEmpty(q);
		deQueue(&q, &e);enQueue(&q, e);
		循环队列
}*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#define MAXSIZE 10
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int front, rare;
}SqQueue;
//-----------------------------------------------------------------
//Create 
void InitcQueue(SqQueue *&q);
void DestroycQueue(SqQueue *&q);
//attributes
bool cQueueIsEmpty(SqQueue *q);
//Operation on elements
bool decQueue(SqQueue *&q, ElemType &e);
bool encQueue(SqQueue *&q, ElemType e);

/*
int main(void)//mian 用以区分main
{
	int e = 0;
	SqQueue *q = NULL;
	InitcQueue(q);

	printf("%d %d\n", e, decQueue(q, e));
	encQueue(q, 12);
	printf("%d %d\n", e, decQueue(q, e));

	printf("%d\n\n", cQueueIsEmpty(q));
	encQueue(q, 1);
	encQueue(q, 2);
	encQueue(q, 3);
	printf("%d %d\n", e, decQueue(q, e));printf("%d %d\n", e, decQueue(q, e));printf("%d %d\n", e, decQueue(q, e));

	DestroycQueue(q);
	system("pause");
	return 0;
}
*/
//-----------------------------------------------------------------
//Create 
void InitcQueue(SqQueue *&q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	if (q == NULL) { printf("Error in malloc!\n"); exit(EXIT_FAILURE); }
	q->front = q->rare = 0;//******1
}
void DestroycQueue(SqQueue *&q)
{
	free(q);
}
//attributes
bool cQueueIsEmpty(SqQueue *q)
{
	return (q->front == q->rare);
}
//Operation on elements
bool decQueue(SqQueue *&q, ElemType &e)
{
	if (cQueueIsEmpty(q))
		return false;
	else
	{
		q->front = (q->front+1)%MAXSIZE;
		e = q->data[q->front];
		return true;
	}
}
bool encQueue(SqQueue *&q, ElemType e)
{
	if ((q->rare+1)%MAXSIZE == q->front)
		return false;
	else
	{
		q->rare = (q->rare+1)%MAXSIZE;
		q->data[q->rare] = e;
		return true;
	}
}