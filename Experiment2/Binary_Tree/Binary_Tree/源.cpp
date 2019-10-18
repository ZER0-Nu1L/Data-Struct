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
//**********                        *函数声明*                     ******************
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
//**********                         *主函数*                      ******************
//***********************************************************************************
int main(void)
{
	BT *B1 = NULL, *B2 = NULL, *B3 = NULL;
	//**********建立B1并初始化**********
	char* str = FiletoStr(INIT_FILE_NAME);//用于递归建立二叉树
	B1 = CreateBT(B1, str);
													//其实可以进一步封装、、、、、
//	free(str);
	Preorder_Save(B1, FILE_NAME);
	//**********建立B2的没有#的结点**********
	Deserialize_CreatBT(B2, FILE_NAME);

	//**********建立B3的没有#的结点**********
	Deserialize_NoRecCreatBT(B3, FILE_NAME);
	//**********非递归中序、后序遍历B1、B2、B3**********
	printf("Non-recursive middle and post-order traverse BTree 1\n");
	InOrderNoRec(B1);
	PostOrderNoRec(B1);
	
	printf("Non-recursive middle and post-order traverse BTree 2\n");
	InOrderNoRec(B2);
	PostOrderNoRec(B2);

	printf("Non-recursive middle and post-order traverse BTree 3\n");
	InOrderNoRec(B3);
	PostOrderNoRec(B3);

	//**********销毁释放B1、B2、B3**********
	DestroyBT(B1); DestroyBT(B2); DestroyBT(B3);
	system("pause");
	return 0;
}
//***********************************************************************************
//**********                        *函数原型*                     ******************
//***********************************************************************************

//***********************************************************************************
//一个将文件中的字符读出并返回的函数
//大大减少了代码复用; 动态申请空间、节约空间; 不用在主函数中申请多余的字符串数组；保证函数封装性
//存在的问题是没有释放空间？
//***********************************************************************************
char* FiletoStr(const char *filename)
{
	FILE* fp = fopen(filename, "rb");
	while (fp == NULL)
	{
		printf("The file can't be opened!\n");
		return '\0';
	}
	fseek(fp, 0, SEEK_END);//计算文件中字符串的长度
	int length = ftell(fp);
	rewind(fp);

	char* buffer = (char*)malloc(sizeof(char)*length);	//申请空间，读取文本
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
//采用二叉链式存储创建二叉树B1//
//并用初始化文件对二叉树B1进行初始化//
//***********************************************************************************
BT* CreateBT(BT* tree, char *& str)//函数返回值就是建立的树，从而实现递归
{
	if (*str == '#') //&&&&&&&&&&&
		tree = NULL;
	else
	{
		tree = (BT*)malloc(sizeof(BT));//最开始传进来的是B1是空树！
		tree->data = *str;
//		printf("%c", *str);
		tree->lchild = CreateBT(tree->lchild, ++str);
		tree->rchild = CreateBT(tree->rchild, ++str);
	}
	return tree;
}
//***********************************************************************************
//void Preorder_Save(BT* tree, const char* filename)的子函数
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
//将文件先序遍历并输出，最后写进fp对应的指针中
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
//从文件中读出序列，并反序列化的递归方法构造二叉树
//***********************************************************************************
void Deserialize_CreatBT(BT*& tree, const char* filename)
{
	char * str = FiletoStr(filename);
	tree = CreateBT(tree, str);
}

void Deserialize_NoRecCreatBT(BT*& tree, const char* filename)
{
	char * str = FiletoStr(filename);	//如何保留根结点
	LinkStNode *st;
	InitStack(st);
	BT *p, *r = NULL;
	//tree = p;//此时的值传递是没有意义的
	bool tag = false;

	r = (BT*)malloc(sizeof(BT));
	r->lchild = r->rchild = NULL;//初始化做到位！
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

	while (*str != '\0' && !isspace(*str) && *str != '\n' && (isalpha(*str) || *str == '#'))//可能字符串后面有无意义的输入 Empty
	{
		while (*str != '#')
		{
			r = (BT*)malloc(sizeof(BT));
			r->lchild = r->rchild = NULL;	//初始化做到位！
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
		str++;		//因为'#'也占了一个位置，所以也要str++
	}
}
//***********************************************************************************
//用非递归方法中序遍历树并输出
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
//用非递归方法后序遍历树并输出
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
//销毁释放树
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