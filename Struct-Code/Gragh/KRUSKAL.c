#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
#define M 10

typedef struct{
	int data;    //顶点信息
	int set;    //判断在哪个连通分量中
}VEX;
typedef struct {
	int vexh, vext;  //边依附的两顶点
	int weight;        //边的权值
	int flag;          //标志域,表示候选还是被抛弃还是什么
}EDGE;
//???这不是典型的存储方式？
int main(void)//minitree_KRUSKAL
{
	int n, i, m, min, k, j;//n顶点数，m边数
	VEX t[M];
	EDGE  e[M];

	printf("Input number of vertex and edge:");
	scanf("%d %d", &n, &m);
	for (i = 1;i <= n;i++)//输入n个顶点，并分成n个连通分量
	{
		printf("t[%d].data=:", i);
		scanf(" %d", &t[i].data);
		t[i].set = i;
	}
	for (i = 0;i < m;i++)//输入m条边
	{
		printf("vexh,vext,weight:");
		scanf("%d %d %d", &e[i].vexh, &e[i].vext, &e[i].weight);
		e[i].flag = 0;
	}

	i = 1;

	while (i < n)		//n-1次建立最小生成树（半对），不能用for()
	{
		min = MAX;				//和上一个一样
		for (j = 0; j < m; j++)	//从所有的结点（e[]）中选取未访问过的权最小的边
		{
			if (e[j].weight < min && e[j].flag == 0)//flag==0意味着还未被抛弃
			{
				min = e[j].weight;
				k = j;			//k记录目前权重最小的边的序号 （e[k].weight min）
			}
		}
		if (t[e[k].vexh].set != t[e[k].vext].set)//选中的边连接的2个顶点属于不同的连通分量
		{
			e[k].flag = 1;//边纳入树中
			for (j = 1;j <= n;j++)//遍历所有的结点，将k对应的弧的尾和头顶点set改为一致（这里改弧尾元素的）
				if (t[j].set == t[e[k].vext].set && j != k)//这里不能是改他自身，改了的话，后面的就找不到了，所以放到循环之外
					t[j].set = t[e[k].vexh].set;
			t[e[k].vext].set = t[e[k].vexh].set;
			i++;//填入结点，生成树多了一个
		}
		else
			e[k].flag = 2;//舍弃掉
	}

	//输出
	for (i = 0;i < m;i++)
		if (e[i].flag == 1)
			printf("%d,%d :%d\n", e[i].vexh, e[i].vext, e[i].weight);
