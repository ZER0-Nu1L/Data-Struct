#define N 10
#define MAX 1000
typedef struct node{
	int adjvex;
	struct struct node nextarc;
}Edge;
typedef struct node{
	int data;
	Edge firstarc;
}Vex;
Vex G[N];

void BFS(Vex G[], int n, int k, int visited[])
{
	int qu[N], r, f;
	f = r = 0;
	int v, index;
	Edge *p = NULL;
	
	printf("%d", k);
	qu[0] = k; visited[k] = 1;

	while(f <= r)//  == 
	{
		v = qu[f++];
		// printf("%d",G[v].data);
		p = G[v].firstarc;
		while( p != NULL)
		{
			v = p.adjvex;//！！！！！！！！！！！！！1
			if(!visited[p])
			{
				printf("%d", v);
				visited[v] = 1;
				qu[++r] = v;
			}
			p = p.nextarc;
		}
	}
}

void traverse(Vex G[], int n, int visited[])
{
	for(int i = 0; i < n; i++)
		visited[i] = 0;
	for(int i = 0; i < n; i++)
		if(!visited[i])
			bfs(G, n, i, visited);
}
