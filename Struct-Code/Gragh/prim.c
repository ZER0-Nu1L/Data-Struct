//Prim
#define M 30
#define MAX 100
void Prim(int ad[][M], int n) //ad是邻接矩阵
{
	int i, j, k, p, q, min;
	q = p = n - 1;
	ad[q][q] = 1;

	for (k = 0;k < (n - 1);k++)
	{
		min = MAX;
		for (i = 0;i < n;i++)
			if (ad[i][i] == 1)
				for (j = 0;j < n;j++)
					if ((ad[j][j] == 0) && (ad[i][j] < min))
					{
						min = ad[i][j];
						p = i;
						q = j;
					}
		ad[q][q] = 1;
		printf("%d %d %d\n", p + 1, q +	 1, ad[p][q]);
		ad[p][q] = ad[q][p] = 0;
	}
}