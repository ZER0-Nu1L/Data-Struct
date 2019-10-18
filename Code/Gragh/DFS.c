#include <stdio.h>
#include <stdlib.h>

#define M 50
#define ElemType int
#define DG 1//有向图？无向图

#define FROMFILE 1//this micro determines how to input the data

typedef struct node{
	int  adjvex;
    struct node *next;
}JD;
typedef   struct  tnode{
	int  vexdata; 
    struct  node  *firstarc;
}TD;
//邻接表的存储方式
TD VEX[M];

void dfs(TD g[],int v,int visited[])//v 表示深度搜索的结点（把它作为初始结点）
{  JD *w;
   int i;
   printf("%d\n",v);//输出初始结点，基例
   visited[v] = 1;
   
   w = g[v].firstarc;
   while(w != NULL)
   {  
		i = w -> adjvex;	//得到函数参数
		if(visited[i] == 0)	//链条
			dfs(g, i, visited);
		w = w->next;
   }
}
void DFS(TD G[], int n, int i, int visited[])
{
	printf("%d\n", i);
	visited[i] = 1;
	
	JD *p = G[i].firstarc;//...........
	int v;
	while(p != NULL)
	{
		v = p->adjvex;
		if(!visited[v])          //vvvvvvvvvvvvvvv 
			DFS(G, n, v, visited);
		p = p->next;
	}
}
void traver(TD g[],int n)
{  
   static int visited[M];
   for(int i = 1;i <= n; i++)
      visited[i] = 0;
   for(int i = 1;i <= n; i++)
      if(visited[i] == 0)
         dfs(g, i, visited);
         
	for(int i = 1;i <= n; i++)
      visited[i] = 0;
	for(int i = 1;i <= n; i++)
      if(!visited[i])
         DFS(g, n, i, visited);
}


int searchnode(int n,ElemType x)
{
	for (int i=1;i<=n;i++)
	{
		if(x==VEX[i].vexdata)
			return i;
	}
	return 0;
}
void display(TD g[],int n)
{
	JD *p;
	for (int i=1;i<=n;i++)
	{
		p = VEX[i].firstarc;
		printf("\n%d",VEX[i].vexdata);
		while (p)
		{
			printf("-->%d",p->adjvex);
			p = p->next;
		}
	}
}

int CreateGraph()
{
	int n,i,m;//né¡¶ç‚¹æ•°ï¼Œmè¾¹æ•°
	ElemType head, tail;
	int headindex,tailindex;
	JD* p;
    
    printf("Input number of vertex and edge:");
    scanf("%d,%d",&n,&m);
	
    for(i=1;i<=n;i++)//è¾“å…¥nä¸ªé¡¶ç‚¹
    {  getchar(); 
	printf("v[%d].data=:",i);
	scanf("%d",&VEX[i].vexdata);
	VEX[i].firstarc=NULL;
    }
    for(i=0;i<m;i++)//è¾“å…¥mæ¡è¾¹
    {
		getchar();
		printf("vexh,vext:");
	scanf("%d,%d",&tail, &head);
	headindex = searchnode(n,head);
	tailindex = searchnode(n,tail);

	p=(JD*)malloc(sizeof(JD));
	p->adjvex = headindex;
	p->next = VEX[tailindex].firstarc;
	VEX[tailindex].firstarc = p;
	
	if(!DG)
	{
		p=(JD*)malloc(sizeof(JD));
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
	fp=fopen("data1.txt","r");
	if(!fp)
	{
		printf("the file does not exist!\n");
		return -1;
	}
	
	int n,i,m;//né¡¶ç‚¹æ•°ï¼Œmè¾¹æ•°
	ElemType head, tail;
	int headindex,tailindex;
	JD* p;
	fscanf(fp,"%d,%d",&n,&m);
	
    for(i=1;i<=n;i++)//è¾“å…¥nä¸ªé¡¶ç‚¹
    {  
	
	fscanf(fp,"%d",&VEX[i].vexdata);
	VEX[i].firstarc=NULL;
    }
    for(i=0;i<m;i++)//è¾“å…¥mæ¡è¾¹
    {
		
	fscanf(fp,"%d,%d",&tail, &head);
	headindex = searchnode(n,head);
	tailindex = searchnode(n,tail);

	p=(JD*)malloc(sizeof(JD));
	p->adjvex = headindex;
	p->next = VEX[tailindex].firstarc;
	VEX[tailindex].firstarc = p;
	
	if(!DG)
	{
		p=(JD*)malloc(sizeof(JD));
	p->adjvex = tailindex;
	p->next = VEX[headindex].firstarc;
	VEX[headindex].firstarc = p;
	}
    }
	fclose(fp);
	return n;
}

int main(void)
{  
	int n=0;
#ifdef FROMFILE
	n=CreateGraph1();
#else
	n=CreateGraph();
#endif
	display(VEX,n);
	printf("\n\n");
	traver(VEX, n);
}
