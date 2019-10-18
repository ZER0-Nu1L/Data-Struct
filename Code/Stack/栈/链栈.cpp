/*ADT Stack
{
	data object:
		D = {a[i]|1<=i<=n, n>0, the type of a[i] is ElemType}
	data relation:
		R = {<a[i], a[i+1]>| a[i], a[i+1] belongs to D, i = 1, 2, 3……}
	fundamental operation:
		InitStack(&s);DestroyStack(&s);
		StackIsEmpty(s);GetTop(s);
		Push(s);Pop(s);
		链栈
}*/
#include <stdio.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef char ElemType;
typedef struct linknode
{
	ElemType data;				//数据域
	struct linknode *next;		//指针域
} LinkStNode;	//命名:link stack(链栈) node(一个结点)
			//LinkStNode不需要top，因为其头结点一直保持记录
//-----------------------------------------------------------------
//Create 
void InitStack(LinkStNode *&s)
{
	s = (LinkStNode *)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
void DestroyStack(LinkStNode *&s)//和链表的销毁类似
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
//attributes
bool StackEmpty(LinkStNode *s)
{
	return(s->next == NULL);
}
bool GetTop(LinkStNode *s, ElemType &e)
{
	if (s->next == NULL)		//栈空的情况
		return false;
	e = s->next->data;
	return true;
}
//Operation on elements
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