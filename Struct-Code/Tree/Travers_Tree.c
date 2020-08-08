//preorder & inorder & postorder
#include <stdio.h>
#include <stdlib.h>

#define FROMFILE 1//this micro determines how to input the data
static char* p;

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
}JD;

void inorder(JD *bt)
{
	if (bt != NULL)
	{
		inorder(bt->lchild);
		printf("%c\t", bt->data);
		inorder(bt->rchild);
	}
}

void preorder(JD *bt)
{
	if (bt != NULL)
	{
		printf("%c\t", bt->data);
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}

void postorder(JD *bt)
{
	if (bt != NULL)
	{
		postorder(bt->lchild);
		postorder(bt->rchild);
		printf("%d\t", bt->data);
	}
}
JD *crt_bt_pre(JD *bt)//input by keyboard
{
	char ch;
	printf("ch=");
	scanf("%c", &ch); getchar();//是按照先序遍历的顺序创建树的 

	if (ch == ' ')  bt = NULL;//不会再递归下去了，递归思想算是基例 
	else
	{
		bt = (JD *)malloc(sizeof(JD));
		bt->data = ch;
		bt->lchild = crt_bt_pre(bt->lchild);//递归建立树 
		bt->rchild = crt_bt_pre(bt->rchild);
	}
	return(bt);
}

JD *crt_bt_pre1(JD *bt, char* ch)//from file
{
	if (*ch == '0')  bt = NULL;
	else
	{
		bt = (JD *)malloc(sizeof(JD));
		bt->data = *ch;

		bt->lchild = crt_bt_pre1(bt->lchild, ++p);
		bt->rchild = crt_bt_pre1(bt->rchild, ++p);
	}
	return(bt);
}

int main()
{  /* ABC00DE0G00F000  */
	JD *head = NULL;
#ifdef FROMFILE
	FILE* fp;
	long size;
	char* buffer;

	size_t result;
	fp = fopen("C:\\Users\\wcb53\\Desktop\\DS\\Tree\\data1.txt", "r");
	if (!fp)
	{
		printf("the file does not exist!\n");
		return 0;
	}

	fseek(fp, 0, SEEK_END);//set the pointer 0 offset from end
	size = ftell(fp);
	rewind(fp);//set the pointer to the beginning of the file from the current position

	buffer = (char*)malloc(sizeof(char)*size);
	result = fread(buffer, 1, size, fp);
	if (result != size)
	{
		printf("Reading error,%d\n", result);
		return -1;
	}
	fclose(fp);
	p = buffer;
	head = crt_bt_pre1(head, p);
	//之所以用p，而不是用buffer，是因为在函数中会对p进行修改，
	//为什么？？？？？？ 
#else
	head = crt_bt_pre(head);
#endif
	printf("\n the preorder is:\n");
	preorder(head);
	printf("\n the inorder is:\n");
	inorder(head);
	printf("\n the postorder is:\n");
	postorder(head);
	return 0;
}
