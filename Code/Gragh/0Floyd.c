#include<limits.h>
#define N 10
#define MAX 1000

void Folyd(int cost[][N], int n, int path[][N], int length[][N])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			length[i][j] = cost[i][j];
			if(length[i][j] > MAX)
				path[i][j] = 0;
			else if(i == j)
				path[i][j] = 0;
			else
				path[i][j] = i+1;
		}
	}
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(length[i][k]+length[k][j] < length[i][j])
				{
					length[i][j] = length[i][k]+length[k][j];
					path[i][j] = path[i][k];
				}
}