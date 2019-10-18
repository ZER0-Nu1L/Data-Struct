#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include"VarDeclaration.h"
#include"Stack.h"

#define FILE_NAME "treedata.dat"
#define INIT_FILE_NAME "init_data.txt"
//#define FROMFILE 1

//***********************************************************************************
//**********                        *��������*                     ******************
//***********************************************************************************
BT* CreateBT(BT* tree, char *& str);
//the function used to test CreateBT()
void Preorder(BT* tree, FILE *& fp);
char* FiletoStr(const char *filename);
void Preorder_Save(BT* tree, const char* filename);
void Deserialize_CreatBT(BT*& tree, const char* filename);
void Deserialize_NoRecCreatBT(BT*& tree, const char* filename);
void InOrderNoRec(BT* tree);
void PostOrderNoRec(BT* tree);
void DestroyBT(BT* tree);

//***********************************************************************************
//**********                         *������*                      ******************
//***********************************************************************************
int main(void)
{
	BT *B1 = NULL, *B2 = NULL, *B3 = NULL;
	//**********����B1����ʼ��**********
	char* str = FiletoStr(INIT_FILE_NAME);//���ڵݹ齨��������
	B1 = CreateBT(B1, str);
													//��ʵ���Խ�һ����װ����������
//	free(str);
	Preorder_Save(B1, FILE_NAME);
	//**********����B2��û��#�Ľ��**********
	Deserialize_CreatBT(B2, FILE_NAME);

	//**********����B3��û��#�Ľ��**********
	Deserialize_NoRecCreatBT(B3, FILE_NAME);
	//**********�ǵݹ����򡢺������B1��B2��B3**********
	printf("Non-recursive middle and post-order traverse BTree 1\n");
	InOrderNoRec(B1);
	PostOrderNoRec(B1);
	
	printf("Non-recursive middle and post-order traverse BTree 2\n");
	InOrderNoRec(B2);
	PostOrderNoRec(B2);

	printf("Non-recursive middle and post-order traverse BTree 3\n");
	InOrderNoRec(B3);
	PostOrderNoRec(B3);

	//**********�����ͷ�B1��B2��B3**********
	DestroyBT(B1); DestroyBT(B2); DestroyBT(B3);
	system("pause");
	return 0;
}
//***********************************************************************************
//**********                        *����ԭ��*                     ******************
//***********************************************************************************

//***********************************************************************************
//һ�����ļ��е��ַ����������صĺ���
//�������˴��븴��; ��̬����ռ䡢��Լ�ռ�; �����������������������ַ������飻��֤������װ��
//���ڵ�������û���ͷſռ䣿
//***********************************************************************************
char* FiletoStr(const char *filename)
{
	FILE* fp = fopen(filename, "rb");
	while (fp == NULL)
	{
		printf("The file can't be opened!\n");
		return '\0';
	}
	fseek(fp, 0, SEEK_END);//�����ļ����ַ����ĳ���
	int length = ftell(fp);
	rewind(fp);

	char* buffer = (char*)malloc(sizeof(char)*length);	//����ռ䣬��ȡ�ı�
	int res = fread(buffer, sizeof(char), length, fp);	//result
	buffer[length] = '\0';									//------------
	if (res != length)
	{
		printf("Error in reading\n");
		return '\0';
	}
	fclose(fp);
	return buffer;
}
//***********************************************************************************
//���ö�����ʽ�洢����������B1//
//���ó�ʼ���ļ��Զ�����B1���г�ʼ��//
//***********************************************************************************
BT* CreateBT(BT* tree, char *& str)//��������ֵ���ǽ����������Ӷ�ʵ�ֵݹ�
{
	if (*str == '#') //&&&&&&&&&&&
		tree = NULL;
	else
	{
		tree = (BT*)malloc(sizeof(BT));//�ʼ����������B1�ǿ�����
		tree->data = *str;
//		printf("%c", *str);
		tree->lchild = CreateBT(tree->lchild, ++str);
		tree->rchild = CreateBT(tree->rchild, ++str);
	}
	return tree;
}
//***********************************************************************************
//void Preorder_Save(BT* tree, const char* filename)���Ӻ���
void Preorder(BT* tree, FILE *& fp)
{
	if (tree != NULL)
	{
		printf("%c", tree->data);
		fprintf(fp, "%c", tree->data);
		Preorder(tree->lchild, fp);
		Preorder(tree->rchild, fp);
	}
	else
	{
		printf("#");
		fprintf(fp,"#");
	}
	return ;
}
//***********************************************************************************
//���ļ������������������д��fp��Ӧ��ָ����
//***********************************************************************************
void Preorder_Save(BT* tree, const char* filename)
{
	FILE* fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		printf("The file can't be opened!\n");
		return ;
	}
	Preorder(tree, fp);
	printf("\n");
	fclose(fp);
}
//***********************************************************************************
//���ļ��ж������У��������л��ĵݹ鷽�����������
//***********************************************************************************
void Deserialize_CreatBT(BT*& tree, const char* filename)
{
	char * str = FiletoStr(filename);
	tree = CreateBT(tree, str);
}

void Deserialize_NoRecCreatBT(BT*& tree, const char* filename)
{
	char * str = FiletoStr(filename);	//��α��������
	LinkStNode *st;
	InitStack(st);
	BT *p, *r = NULL;
	//tree = p;//��ʱ��ֵ������û�������
	bool tag = false;

	r = (BT*)malloc(sizeof(BT));
	r->lchild = r->rchild = NULL;//��ʼ������λ��
	if (*str == '\0' || isspace(*str) || *str == '#')
	{
		r = NULL;
		tree = NULL;
		return;
	}
	r->data = *str;
	str++;
	Push(st, r);
	tree = p = r;

	while (*str != '\0' && !isspace(*str) && *str != '\n' && (isalpha(*str) || *str == '#'))//�����ַ�������������������� Empty
	{
		while (*str != '#')
		{
			r = (BT*)malloc(sizeof(BT));
			r->lchild = r->rchild = NULL;	//��ʼ������λ��
			r->data = *str;
			str++;
			if (tag)
			{
				p->rchild = r;
				tag = false;
				p = p->rchild;
			}				
			else
			{
				p->lchild = r;
				p = p->lchild;
			}
			Push(st, r);
		}
		Pop(st, p);
		tag = true;
		str++;		//��Ϊ'#'Ҳռ��һ��λ�ã�����ҲҪstr++
	}
}
//***********************************************************************************
//�÷ǵݹ鷽����������������
//***********************************************************************************
void InOrderNoRec(BT *b)
{
	BT *p;
	LinkStNode *st;
	InitStack(st);
	if (b != NULL)
	{
		p = b;
		while (!StackEmpty(st) || p != NULL)
		{
			while (p != NULL)
			{
				Push(st, p);
				p = p->lchild;
			}
			if (!StackEmpty(st))
			{
				Pop(st, p);
				printf("%c ", p->data);
				p = p->rchild;
			}
		}
		printf("\n");
	}
	DestroyStack(st);
}
//***********************************************************************************
//�÷ǵݹ鷽����������������
//***********************************************************************************
void PostOrderNoRec(BT *tree)
{
	BT *p, *r;
	bool flag;
	LinkStNode *st;
	InitStack(st);
	p = tree;
	do
	{
		while (p != NULL)
		{
			Push(st, p);
			p = p->lchild;
		}
		r = NULL;
		flag = true;
		while (!StackEmpty(st) && flag)
		{
			GetTop(st, p);
			if (p->rchild == r)
			{
				printf("%c ", p->data);
				Pop(st, p);
				r = p;
			}
			else
			{
				p = p->rchild;
				flag = false;
			}
		}
	} while (!StackEmpty(st));
	printf("\n");
	DestroyStack(st);
}
//***********************************************************************************
//�����ͷ���
//***********************************************************************************
void DestroyBT(BT* tree)
{
	if (tree != NULL)
	{
		DestroyBT(tree->lchild);
		DestroyBT(tree->rchild);
		free(tree);
	}
}