#ifndef STACK_H   //保护头文件 
#define STACK_H

typedef char ElemType;
typedef struct linknode LinkStNode;

void InitStack(LinkStNode *&s);
void DestroyStack(LinkStNode *&s);
bool StackEmpty(LinkStNode *s);
void Push(LinkStNode *&s, ElemType e);
bool Pop(LinkStNode *&s, ElemType &e);
bool GetTop(LinkStNode *s, ElemType &e);

#endif
