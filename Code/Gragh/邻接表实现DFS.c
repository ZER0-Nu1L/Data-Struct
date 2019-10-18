#include <stdio.h>
#include<stdlib.h>

#define FILE_NAME "DFS_data" 
//邻接表法的结构
#define MaxVertexNum 100	//最大结点数
typedef char VertexType;
typedef struct node {
	int adjvex;				//邻接点域
	struct node *nextarc;	//链域,指向下一个顶点
}EdgeNode；
typedef struct vnode {		//表头结点
	VertexType vexdata;		//顶点域（存放顶点信息）
	EdgeNode *firstarc;		//边表头指针
}VertexNode;
typedef VertexNode AdjList[MaxVertexNum]; //AdjList是邻接表类型

void check_null(void)
{
	FILE * fp = NULL;
	if ((fp = fopen(FILE_NAME, "r")) == NULL)
	{
		printf(
			"The file is not exist!\n"
			"Now we create one for you!\n"
		);
		fp = fopen(FILE_NAME, "w");
	}
	fclose(fp);
}	
	
void CreatGraph()
{
	check_null();
	FILE *fp = fopen(FILE_NAME, "r");
}
void dfs(AdjList gra, int v, int visited[])//对一个结点进行DFS
{
	int index = 0;
	printf("%c", gra[v].vexdata);
	visited[v] = 1;
	//思考为什么能用firstarc（结合PPT动画图片就能理解），递归的合理性
	EdgeNode *w = gra[v].firstarc;
	while (w != NULL)
	{
		index = w->adjvex;
		if (!visited[index])
			dfs(gra, index, visited);
		w = w->nextarc;
	}
}
void traver(AdjList gar, int visited[], int n)
{
	for (int i = 0; i <= n; i++)
		visited[i] = 0;
	for (int i = 0; i <= n; i++)
		if (!visited[i])
			dfs(gra, i, visited);
}
int main(int argc, char *arcv[]);
{
	AdjList gra;
	int visited[MAXNODE];

	return 0;
}
