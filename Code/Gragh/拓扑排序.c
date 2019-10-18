#include <stdio.h>
#include <stdlib.h>

#define M 50
#define ElemType int

#define FROMFILE 1//this micro determines how to input the data

typedef struct node{
	int adjvex;
	struct node *next;
}JD;
typedef struct tnode{
	ElemType vexdata;
	int in;					//多加了入度
	struct node *firstarc;
}TD;

TD VEX[M];

int searchnode(int n, ElemType x)
{
	for (int i = 1;i <= n;i++)
	{
		if (x == VEX[i].vexdata)
			return i;
	}
	return 0;
}
void display(TD g[], int n)
{
	JD *p;
	for (int i = 1;i <= n;i++)
	{
		p = VEX[i].firstarc;
		printf("\n%d,%d", VEX[i].vexdata, VEX[i].in);
		while (p)
		{
			printf("-->%d", p->adjvex);
			p = p->next;
		}
	}
}

int CreateGraph()//from keyboard
{
	int n, i, m;//n顶点数，m边数
	ElemType head, tail;
	int headindex, tailindex;
	JD* p;
	scanf("%d,%d", &n, &m);

	for (i = 1;i <= n;i++)//输入n个顶点
	{

		scanf("%d", &VEX[i].vexdata);
		VEX[i].firstarc = NULL;
		VEX[i].in = 0;
	}
	for (i = 0;i < m;i++)//输入m条边
	{

		scanf("%d,%d", &tail, &head);
		headindex = searchnode(n, head);
		tailindex = searchnode(n, tail);

		p = (JD*)malloc(sizeof(JD));
		p->adjvex = headindex;
		p->next = VEX[tailindex].firstarc;
		VEX[tailindex].firstarc = p;
		VEX[headindex].in++;

	}
	return n;
}

int CreateGraph1()//from file
{
	FILE *fp;
	fp = fopen("C:\\Users\\wcb53\\Desktop\\DS\\Gragh\\data2.txt", "r");
	if (!fp)
	{
		printf("the file does not exist!\n");
		return -1;
	}

	int n, i, m;//n顶点数，m边数
	ElemType head, tail;
	int headindex, tailindex;
	JD* p;
	fscanf(fp, "%d,%d", &n, &m);

	for (i = 1;i <= n;i++)//输入n个顶点
	{

		fscanf(fp, "%d", &VEX[i].vexdata);
		VEX[i].firstarc = NULL;
		VEX[i].in = 0;
	}
	for (i = 0;i < m;i++)//输入m条边
	{

		fscanf(fp, "%d,%d", &tail, &head);
		headindex = searchnode(n, head);
		tailindex = searchnode(n, tail);

		p = (JD*)malloc(sizeof(JD));
		p->adjvex = headindex;
		p->next = VEX[tailindex].firstarc;
		VEX[tailindex].firstarc = p;
		VEX[headindex].in++;

	}
	fclose(fp);
	return n;
}

void toposort(TD g[], int n)//对n个顶点的有向图g进行拓扑排序
{
	int m = 0, k, j;	//k用来记录指向的结点的	//m输出顶点个数(助记:和nd对应)
	int s[M], top = 0;	//s保存入度为0的顶点的栈	//top指向栈顶元素的上一个
	JD *p = NULL;

	for (j = 1; j <= n; j++)//入度为0的顶点入栈
		if (g[j].in == 0)
			s[top++] = j;//从0开始放元素

	while (top > 0)//当栈不为空
	{
		j = s[--top];
		printf("%d  ", g[j].vexdata);
		m++;
		p = g[j].firstarc;
		while (p != NULL)
		{
			k = p->adjvex;	//注意！这里的adjvex其实是之前的vexdata
			g[k].in--;
			if (g[k].in == 0)
				s[top++] = k;
			p = p->next;
		}
	}
	printf("\nm = %d\n", m);
	if (m < n)  printf("The network has a cycle\n");
}

int main()
{
	int n = 0;
#ifdef FROMFILE

	n = CreateGraph1();
#else
	n = CreateGraph();
#endif
	display(VEX, n);
	printf("\n\n");
	toposort(VEX, n);
}
