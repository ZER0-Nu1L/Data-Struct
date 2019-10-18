#ifndef STACK_H   //保护头文件 
#define STACK_H

typedef struct data {
	char  sno[12];
	char  sname[10];
	char  sex[4];
	char  major[20];
}ElemType;

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
#endif