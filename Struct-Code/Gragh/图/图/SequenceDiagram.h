#ifndef SEQUENCEDIAGRAM_H
#define SEQUENCEDIAGRAM_H
#define MAXNODE  100//�����������
typedef vertype int;
typedef struct{
    vertype vertex;  //������Ϣ
}VerNode;
typedef struct {
    int adj;
}Arc;
typedef struct {
    VerNode vexs[MAXNODE];
    Arc arcs[MAXNODE][MAXNODE];
};
typedef int AdjMatrix[MAXNODE][MAXNODE]; //ͼ���ڽӾ���

#endif