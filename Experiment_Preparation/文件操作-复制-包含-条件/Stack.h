#ifndef STACK_H   //保护头文件 
#define STACK_H
#include "..\\文件操作\include_file\include_file\VarDeclaration.h"
//Struct
typedef struct linknode LinkStNode;
//Create 
void InitStack(LinkStNode *&s);
void DestroyStack(LinkStNode *&s);
//attributes
bool StackEmpty(LinkStNode *s);
//Operation on elements
void Push(LinkStNode *&s, ElemType e);
bool Pop(LinkStNode *&s, ElemType &e);
bool GetTop(LinkStNode *s, ElemType &e);

#endif