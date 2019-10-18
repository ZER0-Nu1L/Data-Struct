#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include"Queue.h"

//-----------------------------------------------------------------
//Create 
void InitQueue(LinkQuNode *&q);
void DestroyQueue(LinkQuNode *&q);
//attributes
bool QueueIsEmpty(LinkQuNode *q);
//Operation on elements
bool deQueue(LinkQuNode *&q, DataType &e);
bool enQueue(LinkQuNode *&q, DataType e);

//int main(void)
//{

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
bool deQueue(LinkQuNode *&q, DataType &e)
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
bool enQueue(LinkQuNode *&q, DataType e)
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