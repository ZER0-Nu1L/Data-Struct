#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("Hello World!\n");
    return 0;
}
//邻接矩阵的结构
#define MaxVertexNum 100	//最大顶点数
typedef char VertexType;	//顶点类型
typedef int EdgeType;		//边的权值 这两个也可以用结构去定义其类型
typedef struct{
	VertexType vexs[MaxVertexNum]//顶点表
    EdgeType edges[MaxVertexNum][MaxVertexNum]//邻接矩阵
    int n, e; //图中当前的顶点数和边数
}AdjGraph;
typedef int AdjMatrix[MAXNODE][MAXNODE]; //图的邻接矩阵
//邻接表法的结构
//#define MaxVertexNum 100	//最大结点数
typedef char VertexType;
typedef struct node{
	int adjvex;				//邻接点域(e.g.a,b,c,d,e)与顶点Vi邻接的顶点信息
	int info;				//存储与边或者弧相关的信息,如权重等
	struct node *nextarc;	//链域,指向下一个顶点
}EdgeNode；
typedef struct vnode{		//表头结点
	VertexType vexdata;		//顶点域（存放顶点信息）
	EdgeNode *firstarc;		//边表头指针
}VertexNode;
typedef VertexNode AdjList[MaxVertexNum]; //AdjList是邻接表类型
//十字链表法的结构
#define MaxVertexNum 200//最大结点数
typedef struct node{
	int headvex;					//头域
	struct tailvex;					//尾域
	struct node *hlink, *tlink; 	//链域
}EdgeNode；
typedef struct vnode{				//表头结点
	VertexType vexdata;				//数据域
	EdgeNode *firstin, *firstout;	//边表头指针
}VertexNode;
typedef struct{
	VertexNode Orthlist[];			//十字链表 orthogonal正交的
	int vexnum, arcnum;             //图中当前顶点数和边数
}OrthGraph;
//邻接多重表的结构
#define MaxVertexNum 100             //表结点
typedef struct node
{
	int ivex;							//头域
	int jvex;							//尾域
	struct node *ilink, *jlink;			//链域
}EdgeNode;
typedef struct vnode{					//表头结点
	VertexType data;					//数据域
	EdgeNode *firstedge;				//边表头指针
}VertexNode;
typedef struct{
	VertexNode Orthlist[MaxVertexNum];]	//链域接多重表
	int vexnum, arcnum;					//图中当前顶点数和边数
}OrthGraph;
