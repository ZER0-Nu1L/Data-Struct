/*ADT List
{
	data object:
		D = {a[i]|1<=i<=n, n>0, the type of a[i] is ElemType}
	data relation:
		R = {<a[i], a[i+1]>| a[i], a[i+1] belongs to D, i = 1, 2, 3……}
	fundamental operation:
		IniList(&L);DestroyList(&L)//Create
		ListIsEmpty(L);ListLen(L)		  //attribute
		Display(L)				  //display
		index(L, i)		  		  //get the imformation of element
		GetElem(L, i, &e);PriorElem(L);NextElem(L)//get element
		Insert(&L, i, e);Delet(&, i)//Operation on elements

		带头结点的链表
}*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>

#define MAXN 100 
#define MAX 1000
#define MIN 1

typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
}LinkNode;

//-----------------------------------------------------------------
//Create 
void IniList(LinkNode **list);
void DestroyList(LinkNode **list);
//attributes
bool ListIsEmpty(LinkNode*list);
int ListLen(LinkNode*list);
//display
void Display(LinkNode *list);
int index(LinkNode*list, ElemType e);
int GetElem(LinkNode*list, int i);
//Operation on elements
bool Insert(LinkNode**list, int index, ElemType e);
bool Delete(LinkNode**list, int index);
void randassign1(LinkNode**list, int n);
void randassign2(LinkNode**list, int n);
/*
int main(void)
{
	//srand((unsigned int)time(NULL));

	LinkNode* list = NULL;
	IniList(&list);

	printf("%d\n", ListIsEmpty(list));
	//randassign1(&list, 20);
	randassign2(&list, 20);
	Display(list);

	//printf("%d\n", ListIsEmpty(list));
	//printf("%d\n", ListLen(list));
	//printf("%d\n", index(list, 962));
	//------------------------------------
	//printf("%d\n", GetElem(list, 10));//-12,234,12

	//Insert(&list, 3, 0);
	Delete(&list, 7);
	Display(list);

	DestroyList(&list);
	system("pause");
	return 0;
}
*/
//-----------------------------------------------------------------
//Create 
//建立头结点，置空
void IniList(LinkNode **list)///////////////////////////////if(!list)
{
	*list = (LinkNode*)malloc(sizeof(LinkNode));
	(*list)->next = NULL;
}
//删除所有节点
void DestroyList(LinkNode **list)
{
	LinkNode* p = (*list)->next, *pre = (*list);
	while (p != NULL)
	{
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);
}
//attributes
bool ListIsEmpty(LinkNode *list)
{
	return (list->next == NULL);
}
int ListLen(LinkNode *list)
{
	LinkNode *p = list;
	int count = 0;
	while (p->next != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}
//display
void Display(LinkNode *list)
{
	int count = 1;
	for (LinkNode* p = list->next; p != NULL; p = p->next)
	{
		printf("%d\t", p->data);//%d随Elemype而变
		count++;
		if (count % 6 == 1)
			printf("\n");
	}

	printf("\n");
}
int index(LinkNode *list, ElemType e)
{
	LinkNode * p = list->next;
	int count = 1;
	while (p != NULL)
	{
		if (p->data == e)
			return count;
		count++;p = p->next;
	}
	return -1;
}
//得到第i个元素的数据
int GetElem(LinkNode *list, int i)
{
	LinkNode *p = list;
	if (i < 0)
	{
		printf("Invaild index!\n");
		return -1;
	}
	int j = 0;
	while (p->next != NULL & j < i)
	{
		p = p->next;j++;
	}
	if (p == NULL)
	{
		printf("Invaild index!\n");
		return -1;
	}
	return p->data;
}
//Operation on elements
//插入到Index的后面一个
bool Insert(LinkNode**list, int index, ElemType e)
{
	if (index < 0)
	{
		printf("Invaild index!\n");
		return false;
	}
	LinkNode* p = (*list);
	int j = 0;
	while (j < index - 1 && p != NULL)
	{
		p = p->next;j++;
	}
	if (p == NULL)
	{
		printf("Invaild index!\n");
		return false;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	if (s == NULL) { printf("Error in malloc!\n");exit(EXIT_FAILURE); }
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool Delete(LinkNode**list, int index)
{
	if (index <= 0)
	{
		printf("Invaild index!\n");
		return false;
	}
	LinkNode* p = (*list);
	int j = 1;
	while (j < index - 1 && p != NULL)
	{
		p = p->next;j++;
	}
	if (p == NULL)
	{
		printf("Invaild index!\n");
		return false;
	}
	LinkNode* q = p->next;
	if (q != NULL)
		p->next = q->next;//*********
	free(q);
	return true;
}
void randassign1(LinkNode**list, int n)//头插法
{
	if (list == NULL)
	{
		printf("Your list haven't been initialized!\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
		if (s == NULL) { printf("Error in malloc!\n");exit(EXIT_FAILURE); }
		s->data = rand() % MAX + MIN;
		s->next = (*list)->next;
		(*list)->next = s;
	}
}
void randassign2(LinkNode**list, int n)//尾插法
{
	if (list == NULL)
	{
		printf("Your list haven't been initialized!\n");
		return;
	}
	LinkNode *r = *list;
	for (int i = 0; i < n; i++)
	{
		LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));//********************理解其可行性
		if (s == NULL) { printf("Error in malloc!\n");exit(EXIT_FAILURE); }
		s->data = rand() % MAX + MIN;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}