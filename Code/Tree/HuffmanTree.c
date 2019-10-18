#define M 50
#define MAX 100
typedef  struct
{
	int weight;
	int pa, lc, rc;
}JD;

void huffman(int n, int w[], JD t[])//w权值
{
	int i, j, k, x1, x2, m1, m2;
	for (i = 1;i < (2 * n);i++)//初始化
	{
		t[i].pa = t[i].lc = t[i].rc = 0;
		if (i <= n)
			t[i].weight = w[i];
		else
			t[i].weight = 0;
	}
	for (i = 1;i < n;i++)//选择尚未用过的权值最小的两个节点
	{
		m1 = m2 = MAX;//m1和m2存储节点的值
		x1 = x2 = 0;//x1和x2存储节点的序号
		for (j = 1;j < (n + i);j++)
		{
			if ((t[j].weight < m1) && (t[j].pa == 0))
			{
				m2 = m1;  x2 = x1;
				m1 = t[j].weight;  x1 = j;
			}
			else if ((t[j].weight < m2) && (t[j].pa == 0))
			{
				m2 = t[j].weight; x2 = j;
			}
		}
		k = n + i;
		t[x1].pa = t[x2].pa = k;
		t[k].weight = m1 + m2;
		t[k].lc = x1;
		t[k].rc = x2;
	}
}


