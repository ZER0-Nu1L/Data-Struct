/*ADT Stack
{
	data object:
		D = {a[i]|1<=i<=n, n>0, the type of a[i] is ElemType}
	data relation:
		R = {<a[i], a[i+1]>| a[i], a[i+1] belongs to D, i = 1, 2, 3����}
	fundamental operation:
		InitStack(&s);DestroyStack(&s);
		StackIsEmpty(s);GetTop(s);
		Push(s);Pop(s);
		��ջ
}*/
#include <stdio.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef char ElemType;
typedef struct linknode
{
	ElemType data;				//������
	struct linknode *next;		//ָ����
} LinkStNode;	//����:link stack(��ջ) node(һ�����)
			//LinkStNode����Ҫtop����Ϊ��ͷ���һֱ���ּ�¼
//-----------------------------------------------------------------
//Create 
void InitStack(LinkStNode *&s)
{
	s = (LinkStNode *)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
void DestroyStack(LinkStNode *&s)//���������������
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
	if (s->next == NULL)		//ջ�յ����
		return false;
	e = s->next->data;
	return true;
}
//Operation on elements
void Push(LinkStNode *&s, ElemType e)
{
	LinkStNode *p;
	p = (LinkStNode *)malloc(sizeof(LinkStNode));
	p->data = e;				//�½�Ԫ��e��Ӧ�Ľ��p
	p->next = s->next;		//����p�����Ϊ��ʼ���
	s->next = p;
}
bool Pop(LinkStNode *&s, ElemType &e)
{
	LinkStNode *p;
	if (s->next == NULL)		//ջ�յ����
		return false;
	p = s->next;				//pָ��ʼ���
	e = p->data;
	s->next = p->next;		//ɾ��p���
	free(p);				//�ͷ�p���
	return true;
}