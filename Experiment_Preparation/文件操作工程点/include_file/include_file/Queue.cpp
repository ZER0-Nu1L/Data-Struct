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
#include"Queue.h"

#define MAX 100
typedef int ElemType;
typedef struct qnode{
	ElemType data;
	qnode *next;
}DataNode;
typedef struct {
	DataNode * front;
	DataNode * rare;
}LinkQuNode;
//-----------------------------------------------------------------
//Create 
void InitQueue(LinkQuNode *&q);
void DestroyQueue(LinkQuNode *&q);
//attributes
bool QueueIsEmpty(LinkQuNode *q);
//Operation on elements
bool deQueue(LinkQuNode *&q, ElemType &e);
bool enQueue(LinkQuNode *&q, ElemType e);

//int main(void)
//{
//	int e = 0;
//	LinkQuNode *q = NULL;
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
void InitQueue(LinkQuNode *&q)
{
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	if (q == NULL) { printf("Error in mallloc!\n"); exit(EXIT_FAILURE); }
	q->rare = q->front = NULL;
}
void DestroyQueue(LinkQuNode *&q)
{
	DataNode * pre = q->front, *p;
	if (pre != NULL)
	{
		p = pre->next;
		while (p != NULL)
		{
			free(pre);
			pre = p;p = p->next;
		}
		free(pre);
	}
	free(q);
}
//attributes
bool QueueIsEmpty(LinkQuNode *q)
{
	return q->rare == NULL;
}
//Operation on elements
bool deQueue(LinkQuNode *&q, ElemType &e)
{
	if (q->rare == NULL)
		return false;
	e = q->front->data;
	//DataNode* s = q->front->next;
	//if (s == NULL)
	//	q->rare = q->front = NULL;
	//else
	//or q->front = q->front->next;
	DataNode* t = q->front;
	if(q->front->next == NULL)//or q->rare == q->front(book) both okay!!
		q->rare = q->front = NULL;
	else
		q->front = q->front->next;//	q->front->next = s->next; not right!
	free(t);
	return true;
}
bool enQueue(LinkQuNode *&q, ElemType e)
{
	DataNode* s = (DataNode*)malloc(sizeof(DataNode));
	if (s == NULL) { printf("Error in mallloc!\n"); exit(EXIT_FAILURE); }
	s->next = NULL;
	s->data = e;
	if (q->rare == NULL)
		q->front = q->rare = s;
	else
	{
		q->rare->next = s;
		q->rare = s;
	}
	return true;
}