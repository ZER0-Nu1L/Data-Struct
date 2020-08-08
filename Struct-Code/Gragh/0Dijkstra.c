#include<limits.h>
#define N 100
#define MAX 10000
void Djkstra(int ad[][N], int n, int k, int pre[], int dist[])
{
	k -= 1;
	for(int i = 0; i < n; i++)
	{
		ad[i][i] = 0;
		dist[i] = ad[k][i];
		if(dist[i] > MAX)
			pre[i] = -1;
		else
			pre[i] = k + 1
	}
	int min = INT_MAX, index = -1;

	pre[k] = 0; dist[k] = 0; ad[k][k] = 1
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-1; j++)
		{
			min = INT_MAX;
			if(ad[j][j] != 1 && dist[j] < min)
			{
				min = dist[j]; index = j;
			}

		}
		if(index = -1)
			break;
		else
		{
			ad[index][index] = 1;
			for(int j = 0; j < n; j++)
			{
				if(dist[j] + ad[j][index] < dist[index] && ad[j][j] != 0)
				{
					dist[j] = dist[j] + ad[j][index];
					pre[j] = index + 1;
				}
			}
		}
	}
}