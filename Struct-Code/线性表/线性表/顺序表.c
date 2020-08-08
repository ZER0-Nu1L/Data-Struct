/*ADT List
{
	data object:
		D = {a[i]|1<=i<=n, n>0, the type of a[i] is ElemType}
	data relation:
		R = {<a[i], a[i+1]>| a[i], a[i+1] belongs to D, i = 1, 2, 3����}
	fundamental operation:
		IniList(&L);DestroyList(&L)//Create
		ListIsEmpty(L);ListLen(L)		  //attribute
		Display(L)				  //display
		index(L, i)		  		  //get the imformation of element
		GetElem(L, i, &e);PriorElem(L);NextElem(L)//get element
		Insert(&L, i, e);Delet(&, i)//Operation on elements


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
struct node {
	ElemType data[MAXN];
	int length;
};
typedef struct node List;

//-----------------------------------------------------------------
//Create 
void IniList(List *list);
void DestroyList(List *list);

//The function based on th fundermental of data struct;
bool List_Union(List* list1, List* list2);
bool lList_Merge(List* list1, List* list2, List* list3);
//attributes
bool ListIsEmpty(List list);
int ListLen(List list);
//display
void Display(List *list);
int index(List list, int e);
int GetElem(List list, int i);
//Operation on elements
bool Insert(List* list, int index, int e);
bool Delete(List* list, int index);
void randassign(List*list, int n);
void bubble(List*list);
//==================================================================
//==================================================================

int main(void)
{
	List list1, list2, list3;
	srand((unsigned int)time(NULL));
	IniList(&list1);IniList(&list2);IniList(&list3);
	/*
	printf("%d\n", ListLen(List1));
	printf("%d\n", ListIsEmpty(List1));
	*/
	randassign(&list1, 30);randassign(&list2, 40);randassign(&list3, 30);//���ֵMAXN����
	Display(&list1);Display(&list2);Display(&list3);
	//���¶��ϵز���
	/*
	int randnumber = rand() % ListLen(List1);
	printf("List1 value%d��%d\n", randnumber, index(List1, randnumber));
	randnumber = rand() % ListLen(List1);
	printf("List1 value%d��%d\n", randnumber, index(List1, randnumber));

	randnumber = rand() % ListLen(List1);
	printf("List1 NO.%d��%d\n", randnumber, GetElem(List1, randnumber));
	randnumber = rand() % ListLen(List1);
	printf("List1 NO.%d��%d\n", randnumber, GetElem(List1, randnumber));

	int i, e;
	printf("��������������Ҫ�����λ�úͶ�Ӧ����ֵ��");
	scanf("%d %d", &i, &e);
	Insert(&List1, i, e);
	Display(&List1);

	printf("��������������Ҫɾ����ֵ��λ��");
	scanf("%d", &i);
	Delete(&List1, i);
	Display(&List1);
	*/

	List_Union(&list1, &list2);
	bubble(&list1);bubble(&list3);
	Display(&list1);Display(&list3);

	Destroy(&list2);
	lList_Merge(&list1, &list3, &list2);
	Display(&list2);

	DestroyList(&list1);DestroyList(&list2);DestroyList(&list3);

	/*
	printf("%d\n", ListLen(List1));
	printf("%d\n", ListIsEmpty(List1));
	*/

	system("pause");//���ü��˵����ݽ��в���
	return 0;
}

//==================================================================
//-----------------------------------------------------------------
//Create 
void IniList(List *list)//C++��֧��C99  ��ô���÷�ʽ���ӿ�Ӧ����ô�죿 
{
	//list =(List*) malloc(sizeof(ElemType)*MAXN);
	memset(list->data, 0, MAXN);//*************************û�г�ʼ�����ʵ�length�������Ҳ�ᡭ��
	list->length = 0;
}
void DestroyList(List *list)
{
	memset(list->data, 0, MAXN);
	list->length = 0;
}
//-----------------------------------------------------------------
//attributes
bool ListIsEmpty(List list)
{
	return list.length == 0;
}
int ListLen(List list)
{
	return list.length;
}
//-----------------------------------------------------------------
//display
void Display(List *list)
{
	if (ListIsEmpty(*list))
	{
		printf("Sorry, your list is empty!\b");
		return;
	}
	else
	{
		int lenList = ListLen(*list);
		for (int i = 1; i < lenList + 1; i++)//Ϊ�˸�ʽ�������
		{
			printf("%3d ", list->data[i - 1]);
			if ((i % 10 == 0))
			{
				printf("\n");
			}
		}
		printf("\n");
	}
}
//-----------------------------------------------------------------
//get the imformation of element
int index(List list, int e)
{
	if (e == 0)
	{
		printf("The list is empyt!\n");//*************
		return -1;
	}
	for (int i = 0; i < ListLen(list); i++)
	{
		if (list.data[i] == e)
			return i + 1;	//�������ת�߼����
	}
	return -1;
}
int GetElem(List list, int i)
{
	if (i > ListLen(list) || i < 0)
	{
		printf("The list is empty!\n");
		return -1;
	}
	return list.data[i - 1];
}
//-----------------------------------------------------------------
//Operation on elements
//����ָ����ֵ��ָ������ֵλ��
//��������������Ϸ����������Ա�����������������Ϣ������false
//����ɹ�����true
bool Insert(List* list, int index, int e)
{
	if (index < 0 || index > MAXN)//�Ϸ��Լ��
	{
		printf("Invalid value!\n");
		return false;
	}
	else if (list->length == MAXN)
	{
		printf("The list is full!\n");//����ĺϷ���
		return false;
	}
	else
	{
		index--;//תΪ�������;
		for (int i = ListLen(*list); i > index; i--)//��Ϊi�ĳ�ʼ��ִֻ��һ�Σ�����ֱ�ӷ�ListLen()��Ч��û��Ӱ��
			list->data[i] = list->data[i - 1];
		list->data[index] = e;

		list->length++;//������������Ӱ��
		return true;
	}
}
//ɾ��ָ������ֵ������
//��������������Ϸ����������Ա�Ϊ�գ�����������Ϣ������false
//ɾ���ɹ�����true
bool Delete(List* list, int index)
{
	if (index < 0 || index > ListLen(*list))//�Ϸ��Լ�� 
	{
		printf("Invalid value!\n");
		return false;
	}
	else if (ListIsEmpty(*list))
	{
		printf("The list is empty!\n");//����ĺϷ���
		return false;
	}
	else
	{
		index--;//תΪ�������;
		for (int i = index; i < ListLen(*list) - 1; i++)//-1
			list->data[i] = list->data[i + 1];

		list->length--;//������������Ӱ��
		return true;
	}
}
void randassign(List*list, int n)
{
	if (n < 0 || n > MAXN)
	{
		printf("Error in assignment!\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++)
		list->data[i] = rand() % MAX + MIN;
	list->length = n;                //*******************
}
//-----------------------------------------------------------------
//The function based on th fundermental of data struct;
bool List_Union(List* list1, List* list2)
{
	int len2 = ListLen(*list2), len1 = ListLen(*list1);
	bool flag = false;
	for (int i = 1; i <= len2; i++)
	{
		int value = GetElem(*list2, i);
		if (index(*list1, value) == -1)
		{
			flag = Insert(list1, 1, value);//len1 + i  ************Ҫô�����µı�����Ҫô�Ͳ鵽�̶�λ�á�
			if (!flag) break;//����ʧ�ܾ��˳���
		}
	}
	return flag;
}
void bubble(List*list)
{
	int n = ListLen(*list);
	ElemType temp = 0;
	for (int i = 0; i < n - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (list->data[j] > list->data[j + 1])
			{
				temp = list->data[j]; list->data[j] = list->data[j + 1]; list->data[j + 1] = temp;
				flag = true;
			}
		}
		if (flag == false)break;
	}
}
bool lList_Merge(List* list1, List* list2, List* list3)
{
	int count = 1;
	if (list1 == NULL || list2 == NULL)
		return true;
	int i = 1, j = 1;
	int len1 = ListLen(*list1), len2 = ListLen(*list2);
	while (i < len1 && j < len2)
	{
		int value1 = GetElem(*list1, i);
		int value2 = GetElem(*list2, j);
		if (i <= len1 && value1 < value2)
		{
			Insert(list3, count, value1);
			count++;i++;
		}
		//if (j <= len2 && value1 > value2)
		else
		{
			Insert(list3, count, value2);
			j++;count++;
		}
	}
	if (i < len1)
	{
		for (int k = i; k <= len1; k++)
		{
			int value1 = GetElem(*list1, k);
			Insert(list3, count, value1);
			count++;
		}
	}
	if (j < len2)
	{
		for (int k = j; k <= len2; k++)
		{
			int value2 = GetElem(*list2, k);
			Insert(list3, count, value2);
			count++;
		}
	}
	return true;
}