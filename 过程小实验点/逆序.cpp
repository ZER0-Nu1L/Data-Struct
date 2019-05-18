#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



typedef int ElemType;

typedef struct linknode
{
	ElemType data;
	struct linknode *next;
} LinkStNode;

//Create 
void InitStack(LinkStNode *&s);
void DestroyStack(LinkStNode *&s);
//attributes
bool StackEmpty(LinkStNode *s);
bool GetTop(LinkStNode *s, ElemType &e);
//Operation on elements
void Push(LinkStNode *&s, ElemType e);
bool Pop(LinkStNode *&s, ElemType &e);

int main(void) 
{
	ElemType data[100] = {1,2,3,4,5,6,7,8,9,10};
	LinkStNode *st;
	InitStack(st);
	for(int i = 0; i < 10; i++)
		Push(st, data[i]);
	ElemType e = 0;
	for(int i = 0; i < 10; i++)
	{
		Pop(st, e);
		printf("%d\t", e);
	}
	
	DestroyStack(st);
	return 0;
}


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
	free(s);	//s指向尾结点,释放其空间
}
bool StackEmpty(LinkStNode *s)
{
	return(s->next == NULL);
}
void Push(LinkStNode *&s, ElemType e)
{
	LinkStNode *p;
	p = (LinkStNode *)malloc(sizeof(LinkStNode));
	p->data = e;				//新建元素e对应的结点p
	p->next = s->next;		//插入p结点作为开始结点
	s->next = p;
}
bool Pop(LinkStNode *&s, ElemType &e)
{
	LinkStNode *p;
	if (s->next == NULL)		//栈空的情况
		return false;
	p = s->next;				//p指向开始结点
	e = p->data;
	s->next = p->next;		//删除p结点
	free(p);				//释放p结点
	return true;
}
bool GetTop(LinkStNode *s, ElemType &e)
{
	if (s->next == NULL)		//栈空的情况
		return false;
	e = s->next->data;
	return true;
}
