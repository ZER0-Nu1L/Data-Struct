//用邻接矩阵来实现
//求第k个顶点到各顶点最短距离(ad此时的最大下标是k-1)
void shortpath_DIJ(int ad[][M], int n, int k, int pre[], int dist[])
{
	int i, j, p, wm;
	k = k - 1;//物理与逻辑 <助记>k-key, dis-distance	

	for (i = 0;i < n;i++)
	{
		dist[i] = ad[k][i];//初始化，各个点到k点的距离，k是入度
		if (dist[i] < MAX) 	
			pre[i] = k + 1;//物理与逻辑
		else
			pre[i] = 0;//用0表示不连通
	}
	pre[k] = 0; dist[k] = 0; ad[k][k] = 1;//10和prim一样，看有没有是否仍在集合S中

	for (j = 0;j < (n - 1);j++)//需要n-1次得到所有最短距离的数值
	{
		wm = MAX;  p = -1;//p用来记录路径最小结点的下标
		for (i = 0;i < n;i++)
			if ((ad[i][i] == 0) && (dist[i] < wm))//最短距离顶点
			{
				p = i;
				wm = dist[i];
			}
		if (p == -1)  break;//没有找到，说明已经不存在，  //都不连通了
		else 
		{
			ad[p][p] = 1;//加入到S中
			for (i = 0;i < n;i++)
				if (ad[i][i] == 0)//更新距离表
					if (dist[p] + ad[p][i] < dist[i])//dist[p] + ad[p][i]v0到点p到到i的距离
					{
						dist[i] = dist[p] + ad[p][i];
						pre[i] = p + 1;//更改前驱并将下标改成逻辑序号
					}
		}
	}
}


