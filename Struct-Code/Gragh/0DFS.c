#define N 10
#define MAX 1000
typedef struct node {
	int adjvex;
	struct struct node nextarc;
}Edge;
typedef struct node {
	int data;
	Edge firstarc;
}Vex;
Vex G[N];

void DFS(VEX G[], int n, int i, int visited[])
{
	printf("%d\n", i);
	visited[i] = 1;
	Edge *p = G[i].firstarc;//........
	int v;
	while(p != NULL)
	{
		v = p.adjvex;
		if(!visited[v])          //vvvvvvvvvvvvvvv
			DFS(G, n, v, visited);
		p = p->nextarc;
	}
}

void travese(VEX G[], int n, int i, int visited[])
{
	for(int i = 0; i < n; i++)
		visited[i] = 0;
	for(int i = 0; i < n; i++)
		if(!visited[i])
			DFS(G, n, i, visited);
}