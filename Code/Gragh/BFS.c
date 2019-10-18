//preorder & inorder & postorder
#include <stdio.h>
#include <stdlib.h>

#define M 50
#define ElemType int
#define DG 1//有向图？无向图

#define FROMFILE 1//this micro determines how to input the data

typedef struct node{
	int  adjvex;       		//邻接点域，存放与Vi邻接的点在表头数组中的位置
	struct  node  *next;  	//链域，指示下一条边或弧
}JD;
typedef struct tnode{
	int  vexdata;     //存放顶点信息
	struct node *firstarc;    //指示第一个邻接点
}TD;
TD VEX[M];
//邻接表

void bfs(TD g[], int v, int visited[])//队列的元素是结点的编号
{
	int qu[M], f = 0, r = 0;
	JD *p;
	printf("%d\n", v);	//此函数在入队的时候打印入队的元素
	visited[v] = 1;
	qu[0] = v;			//首结点入列
	while (f <= r)		//队列不为空
	{
		v = qu[f++];			//出列
		p = g[v].firstarc;		//遍历出列元素的所有的邻接点
		while (p != NULL)
		{
			v = p->adjvex;
			if (!visited[v])	//如果没有被访问过的话，就入队
			{
				printf("%d\n", v);
				qu[++r] = v;
				visited[v] = 1;
			}
			p = p->next;
		}
	}
}

void BFS(TD G[], int n, int k, int visited[])
{
	int qu[M], r, f;
	f = r = 0;
	int v, index;
	JD *p = NULL;
	
	printf("%d\n", k);
	qu[0] = k;visited[k] = 1;

	while(f <= r)//  == 
	{
		v = qu[f++];
		// printf("%d",G[v].data);
		p = G[v].firstarc;
		while( p != NULL)
		{
			v = p->adjvex;//��������������������������1
			if(!visited[v])
			{
				printf("%d\n", v);
				qu[++r] = v;
				visited[v] = 1;
			}
			p = p->next;
		}
	}

}

void traver(TD g[], int n)
{
	int i;
	static int visited[M];
	for (i = 1;i <= n;i++)
		visited[i] = 0;
	for (i = 1;i <= n;i++)
		if (visited[i] == 0)
			bfs(g, i, visited);
	printf("\n");
	for (i = 1;i <= n;i++)
		visited[i] = 0;
	for (i = 1;i <= n;i++)
		if (visited[i] == 0)
			BFS(g, n, i, visited);
}

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
		printf("\n%d", VEX[i].vexdata);
		while (p)
		{
			printf("-->%d", p->adjvex);
			p = p->next;
		}
	}
}

int CreateGraph()
{
	int n, i, m;//n顶点数，m边数
	ElemType head, tail;
	int headindex, tailindex;
	JD* p;

	printf("Input number of vertex and edge:");
	scanf("%d,%d", &n, &m);

	for (i = 1;i <= n;i++)//输入n个顶点
	{
		getchar();
		printf("v[%d].data=:", i);
		scanf("%d", &VEX[i].vexdata);
		VEX[i].firstarc = NULL;
	}
	for (i = 0;i < m;i++)//输入m条边
	{
		getchar();
		printf("vexh,vext:");
		scanf("%d,%d", &tail, &head);
		headindex = searchnode(n, head);
		tailindex = searchnode(n, tail);

		p = (JD*)malloc(sizeof(JD));
		p->adjvex = headindex;
		p->next = VEX[tailindex].firstarc;
		VEX[tailindex].firstarc = p;

		if (!DG)
		{
			p = (JD*)malloc(sizeof(JD));
			p->adjvex = headindex;
			p->next = VEX[tailindex].firstarc;
			VEX[tailindex].firstarc = p;
		}
	}
	return n;
}

int CreateGraph1()//from file
{
	FILE *fp;
	fp = fopen("C:\\Users\\wcb53\\Desktop\\DS\\Gragh\\data1.txt", "r");
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

		if (!DG)
		{
			p = (JD*)malloc(sizeof(JD));
			p->adjvex = tailindex;
			p->next = VEX[headindex].firstarc;
			VEX[headindex].firstarc = p;
		}
	}
	fclose(fp);
	return n;
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
	printf("\n");
	traver(VEX, n);
}
