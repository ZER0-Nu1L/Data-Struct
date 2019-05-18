#ifndef QUEUE_H//保护头文件 
#define QUEUE_H
#include "VarDeclaration.h"
//Struct
typedef struct data1 {
	char  sno[12];
	char  sname[10];
	char major[20];
	char  cname[10];
	int  score;
}DataType;

typedef struct qnode {
	DataType data;
	qnode *next;
}DataNode;
typedef struct qqnode {
	DataNode * front;
	DataNode * rare;
}LinkQuNode;

//Create 
void InitQueue(LinkQuNode *&q);
void DestroyQueue(LinkQuNode *&q);
//attributes
bool QueueIsEmpty(LinkQuNode *q);
//Operation on elements
bool deQueue(LinkQuNode *&q, DataType &e);
bool enQueue(LinkQuNode *&q, DataType e);

#endif