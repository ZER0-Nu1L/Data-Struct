//Prim
#define M 30
#define MAX 100
void minispantree_PRIM(int ad[][M], int n) //ad是邻接矩阵
{
	int i, j, k, p, q, wm;//n个结点
	q = p = n - 1;		//最后一个元素放到U中
	ad[q][q] = 1;		//规定对角线没有被选中的时候为0，选中后为一 ； 选中：U中的； 
						//这里初始化放入最后的元素

	for (k = 0;k < (n - 1);k++)	//要连接集合n-1次才能生成树
	{
		wm = MAX;				//记录权重最小的边的权重
		for (i = 0;i < n;i++)	//先i（行）后j（列）——压缩存储-只处理上三角
			if (ad[i][i] == 1)
				for (j = 0;j < n;j++)
					if ((ad[j][j] == 0) && (ad[i][j] < wm))//ad[j][j]==0表示j没有加入U，ad[i][j]是更小的权重
					{
						wm = ad[i][j];
						p = i;
						q = j;				//连接两个集合的权重最小的边
					}
		ad[q][q] = 1;					//纳入结点集
		printf("%d %d %d\n", p + 1, q +	 1, ad[p][q]);
		if (p > q)  ad[p][q] = -ad[p][q];		//<=>ad[p][q]=ad[q][p]=0;
		else     ad[q][p] = -ad[q][p];			//它只对上三角处理，原因式forforij遍历的时候，上三角会先被遍历
	}
}