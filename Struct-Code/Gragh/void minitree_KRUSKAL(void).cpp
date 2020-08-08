#include<stdio.h>
#define MAX 1000
#define M 10

typedef   struct{
	int data;    //顶点信息
	int  set;    //判断在哪个连通分量中
}VEX;
typedef   struct {
	int vexh, vext;  //边依附的两顶点
	int weight;        //边的权值
	int flag;            //标志域,表示候选还是被抛弃还是什么
}EDGE;

int main(void)//minitree_KRUSKAL
{
	int n, i, m, min, k, j;//n顶点数，m边数
	VEX t[M];
	EDGE  e[M];

	printf("Input number of vertex and edge:");
	scanf("%d,%d", &n, &m);
	for (i = 1;i <= n;i++)//输入n个顶点，并分成n个连通分量
	{
		printf("t[%d].data=:", i);
		scanf("%d", &t[i].data);
		t[i].set = i;
	}
	for (i = 0;i < m;i++)//输入m条边
	{
		printf("vexh,vext,weight:");
		scanf("%d,%d,%d", &e[i].vexh, &e[i].vext, &e[i].weight);
		e[i].flag = 0;
	}

	i = 1;

	while (i < n)//n-1次建立最小生成树
	{
		min = MAX;		//和上一个一样
		for (j = 0; j < m; j++)	//从所有的结点（e[]）中选取未访问过的权最小的边
		{
			if (e[j].weight < min && e[j].flag == 0)//flag==0意味着还未被选阿红
			{
				min = e[j].weight;
				k = j;			//k用来记录
			}
		}
		if (t[e[k].vexh].set != t[e[k].vext].set)//选中的边连接的2个顶点属于不同的连通分量
		{
			e[k].flag = 1;//边纳入树中
			for (j = 1;j <= n;j++)//将弧的尾和头顶点set改为一致
				if (t[j].set == t[e[k].vext].set && j != t[e[k].vext].set)
					t[j].set = t[e[k].vexh].set;
			t[e[k].vext].set = t[e[k].vexh].set;
			i++;
		}
		else
			e[k].flag = 2;//舍弃掉
	}

	//输出
	for (i = 0;i < m;i++)
		if (e[i].flag == 1)
			printf("%d,%d :%d\n", e[i].vexh, e[i].vext, e[i].weight);
}