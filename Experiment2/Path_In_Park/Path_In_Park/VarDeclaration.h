#ifndef VAR_DACLARATION_H
#define VAR_DACLARATION_H

#define MAX_SPOT 50
#define MAX_NAME 20
#define MAX_LEN 32767
#define PATH_LEN 50

typedef struct node1 {
	char spot_name[MAX_NAME+1];
	int number;
}SpotType;
typedef struct node {
	int path[MAX_SPOT+1][MAX_SPOT+1];	//邻接矩阵数组
	SpotType spot[MAX_SPOT+1];			//存放顶点信息	
	int n, e;							//顶点数，边数
}Park_map;								//邻接矩阵

//用邻接表实现最后一个快速检索的链表存储
//为了减少名字重复，这里用邻接表最原始的定义的名称，也不在注释
typedef struct node2
{
	int adjvex;
	int distance;
	char thepath[PATH_LEN];
	struct node2 *nextarc;
} Edge;						//边结点类型
typedef struct
{
	SpotType vexdata;
	Edge *firstarc;			//指向第一条边
} Vex;						//邻接表头结点类型
typedef struct
{
	Vex spot[MAX_SPOT + 1];		//邻接表头结点数组
	int n, e;
} Graph;

#endif
