#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

typedef DataType int;
struct node{
	DataType data;
	int lchild, rchild;
}BinTreeNode;
typedef BinTreeNode *BinTree;

void PreOrderTraverse(BinTree BT);
void PreOrderNoRec(BinTree BT);
void InOrderTraverse(BinTree BT);
void InOrderNoRec(BinTree BT);
void PostOrderTraverse(BinTree BT);
void PostOrderNoRec(BinTree BT);

int main(void) 
{
	
	return 0;
}

void PreOrderTraverse(BinTree BT)
{
	if(BT!=NULL)
	{
		printf("%d", BT->data);
		PreOrderTraverse(BT->lchild);
		PreOrderTraverse(BT->rchild);
	}
	return;
}
void InOrderTraverse(BinTree BT)
{
	if(BT!=NULL)
	{
		InOrderTraverse(BT->lchild);
		printf("%d", BT->data);
		InOrderTraverse(BT->rchild);
	}
	return;
}
void PostOrderTraverse(BinTree BT)
{
	if(BT!=NULL)
	{
		PostOrderTraverse(BT->lchild);
		PostOrderTraverse(BT->rchild);
		printf("%d", BT->data);
	}
	return;
}
//-----------------------------
//NoRec------------------------
void PreOrderNoRec(BinTree BT)
{
	BinTree p = BT;
	Stack s = NULL;
	while( !IsEmpty(s) || (p!= NULL))
	{
		if(p != NULL)
		{ 
			printf(p->data);//The order!!
			Push(s, p);
			p = p->lchild;
		}
		else
		{
			p = Pop(s);
			p = p->rchild;
		}
	}
}
void InOrderNoRec(BinTree BT)
{
	BinTree p = BT;
	Stack s = NULL;
	while( !IsEmpty(s) || (p!= NULL))
	{
		if(p != NULL)
		{
			Push(s, p);
			p = p->lchild;
		}
		else
		{
			p = Top(s);
			Pop(s);
			printf("%d", p->data);
			p = p->rchild;
		}
	}	
}
void PostOrderNoRec (BinTree BT) 
{
	stack S, tag;
	BinTree p = BT->root;
	while ((p != NULL) || !StackEmpty(S))
	{
		while (p!=NULL)                    	 
		{ 
			Push (S,p);
			Push (tag,0);
			p = p->lchild;
		}/*ɨ��������*/
		if(!StackEmpty(S))
		{ 
			if (Pop(tag)==1) /*��������������*/
			{ 
				p = Top(S);
				Pop(S);
				printf ("%c", p->data);
				Pop(tag);
			}
			/*���ʽ�㲢��ջ*/
			else
			{
				p=Top(s);
				if(!StackEmpty(S))  /*ɨ��������*/
				{
					p = p->rchild;
					Pop(tag);
					Push(tag,1);
				}
			}
		}
	}
}

int level(BinTree BT, DataType data, int height)
{
	if(BT == NULL) return 0;
	else if(BT->data == data) return height;
	else
	{
		int l = level(BT->lchild, data, height+1);
		return l !=0 ? l : level(BT->rchild, data, height+1);
	}
	
}

//�ݹ����ҵ
//1.���������K��Ľڵ����
int depth(BinTree BT, int k)
{
	if(k = 1) return 1;
	else if(BT == NULL) return 0;
	else if(k < 0) exit(EXIT_FAILURE);
	else return depth(BT->lchild, k-1)+depth(BT->rchild, k-1);
}
//2.�ж����ö������Ƿ�ṹ��ͬ(��������������)
bool SameStruct(BinTree BT1, BinTree BT2)
{
	if((BT1 == NULL) && (BT2 == NULL)) return true;
	else if return (SameStruct(BT1->lchild, BT2->lchild)+SameStruct(BT1->rchild, BT2->rchild) == 0)
}
//3.��������ľ���
BinTree *Mirror(BinTree BT1)
{
	BinTree BT2;
	bt2 = NULL;
	if(BT1 == NULL)
		return NULL;
	else
	{
		BT2->lchild = Mirror(BT1->rchild);
		BT2->rchild = Mirror(BT1->lchild);
		return BT2;
	}
}
