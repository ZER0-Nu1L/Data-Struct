//Q:n与k的关系?
	//A:n是邻接矩阵的大小，k是起点
	//和prim算法不同，prim算法想要的是最小生成树，所以先把最后一个元素放进来
	//而Dijkstra可以是任何一个点
//逻辑与物理声明:
	//pre[]记录的是逻辑序号，函数用的是逻辑序号
	//所有的数组都用的是物理序号

//函数变量声明：
	//图用邻接矩阵来实现
	//n是邻接矩阵的大小
	//#key#			求第k个顶点到各顶点最短距离(ad此时的最大下标是k-1) 
	//#distancde# 	数组dist[]存放V0到每个终点的最短路径长度，其初态为图中直接路径权当前找到的从源点值
	//pre数组用来记录前驱，可以用来输出最短路径
//用dist[]，并且处处判断都用dist[]的重要原因
	//在此算法中不能更改ad矩阵
//重要经验：邻接矩阵的下标ad[i][j],i、j分别对应入度和出度
	//如此就能轻松写出:
	//dist[i] = ad[k][i]
	//dist[index] + ad[index][i] < dist[i]
	
#define MAX 1000
void Dijkstra(int ad[][M], int n, int k, int pre[], int dist[])
{
	k = k - 1;//物理与逻辑
	for(int i = 0; i < n; i++)//初始化，各个点到k点的距离
	{
		dist[i] = ad[k][j];	//dist[]初始化
		if(dist[i] > MAX)	//pre[]初始化
			pre[i] = 0;
		else
			pre[i] = k + 1;//物理与逻辑
	}
	pre[k] = 0; dist[k] = 0; ad[k][k] = 1;
	//1\0和prim一样，看有没有是否仍在集合S中

	int min = MAX, index = -1;//index用来记录路径最小结点的下标
	for(int j = 0; j < n-1; j++)//需要n-1次得到所有最短距离的数值
	{
		for(int i = 0; i < n; i++)
		{
			if(ad[i][i] == 0 && dist[i] < min)
			{
				min = dist[i];
				index = i;
			}
		}

		if(index == -1)//没有找到，说明已经不存在//都不连通了
			break;
		else//刷新距离表
		{
			ad[index][index] = 1;	//加入到S中
			for(int i = 0; i < n; i++)
			{
				if(ad[i][i] == 0)
					if(dist[index] + ad[index][i] < dist[i])
					{
						dist[i] = ad[index] + ad[index][i];
						pr[i] = index + 1;//更改前驱并将下标改成逻辑序号
					}
			}
		}
	}
}