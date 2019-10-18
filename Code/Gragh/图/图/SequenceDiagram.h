#ifndef SEQUENCEDIAGRAM_H
#define SEQUENCEDIAGRAM_H
#define MAXNODE  100//顶点的最大个数
typedef vertype int;
typedef struct{
    vertype vertex;  //顶点信息
}VerNode;
typedef struct {
    int adj;
}Arc;
typedef struct {
    VerNode vexs[MAXNODE];
    Arc arcs[MAXNODE][MAXNODE];
};
typedef int AdjMatrix[MAXNODE][MAXNODE]; //图的邻接矩阵

#endif