/*ADT List
{
	data object:
		D = {a[i]|1<=i<=n, n>0, the type of a[i] is ElemType}
	data relation:
		R = {<a[i], a[i+1]>| a[i], a[i+1] belongs to D, i = 1, 2, 3……}
	fundamental operation:
		InitStack(&s);
		DestroyStack(&s);
		StackIsEmpty(s);
		GetTop(s);
		Push(s);
		Pop(s);

		顺序栈
		栈顶指针指向栈顶元素
}*/
//不用Initialize的原因是：有不同的数据类型，如果用同样的函数，不同的数据结构会起冲突
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MaxSize 100
typedef struct
{
	int xi;
	int yi;
}ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int top;				//栈指针
} SqStack;					//顺序栈类型
//-----------------------------------------------------------------
//Create 
void InitStack(SqStack *&s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}
void DestroyStack(SqStack *&s)
{
	free(s);
}
//attributes
bool StackEmpty(SqStack *s)
{
	return(s->top == -1);
}
bool GetTop(SqStack *s, ElemType &e)
{
	if (s->top == -1) 		//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];
	return true;
}
//Operation on elements
bool Push(SqStack *&s, ElemType e)
{
	if (s->top == MaxSize - 1)    //栈满的情况，即栈上溢出
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack *&s, ElemType &e)
{
	if (s->top == -1)		//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
