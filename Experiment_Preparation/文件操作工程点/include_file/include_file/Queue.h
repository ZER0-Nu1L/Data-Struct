#ifndef QUEUE_H//保护头文件 
#define QUEUE_H
#include "VarDeclaration.h"
//Struct

typedef struct qnode DataNode;
typedef struct LinkQuNode;
//Create 
void InitQueue(LinkQuNode *&q);
void DestroyQueue(LinkQuNode *&q);
//attributes
bool QueueIsEmpty(LinkQuNode *q);
//Operation on elements
bool deQueue(LinkQuNode *&q, ElemType &e);
bool enQueue(LinkQuNode *&q, ElemType e);

#endif 