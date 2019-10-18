/*
    图用邻接矩阵存储
    length[][]存放最短路径长度
    path[i][j]是从Vi到Vj的最短路径上Vj前一顶点序号//跳板
    cost[][M]是邻接矩阵

    和Dijkstra类似，不能直接修改邻接矩阵，另有一个length来记录
*/
void shortpath_FLOYD(int cost[][M], int path[][M], int length[][M], int n)
{
    for (int i = 0;i < n;i++)//两重循环初始化矩阵
    {
        for (int j = 0;j < n;j++)
        {
            length[i][j] = cost[i][j];  //length初始化
                                        //path初始化
            if (i == j) path[i][j] = 0; //对角线元素
            else if (length[i][j] < MAX)
                path[i][j] = i + 1;     //路径前驱元素逻辑序号
            else  path[i][j] = 0;       //无穷大记为0
        }
    }
    int wm =  MAX;
    for (int  k = 0;k < n;k++)
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++) 
                if (length[i][k] + length[k][j] < length[i][j])
                {
                    length[i][j] = length[i][k] + length[k][j];
                    path[i][j] = path[k][j];//前驱元素变成再前一个的元素 k - i - j
                }
}