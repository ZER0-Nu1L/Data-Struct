#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Stack.h"

void InitStack(LinkStNode *&s)
{
	s = (LinkStNode *)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
void DestroyStack(LinkStNode *&s)
{
	LinkStNode *p = s->next;
	while (p != NULL)
	{
		free(s);
		s = p;
		p = p->next;
	}
	free(s);
}
bool StackEmpty(LinkStNode *s)
{
	return(s->next == NULL);
}
void Push(LinkStNode *&s, ElemType e)
{
	LinkStNode *p;
	p = (LinkStNode *)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
bool Pop(LinkStNode *&s, ElemType &e)
{
	LinkStNode *p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}
bool GetTop(LinkStNode *s, ElemType &e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}