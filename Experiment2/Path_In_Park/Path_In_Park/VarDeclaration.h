#ifndef VAR_DACLARATION_H
#define VAR_DACLARATION_H

#define MAX_SPOT 50
#define MAX_NAME 20
#define MAX_LEN 32767
#define PATH_LEN 50

typedef struct node1 {
	char spot_name[MAX_NAME+1];
	int number;
}SpotType;
typedef struct node {
	int path[MAX_SPOT+1][MAX_SPOT+1];	//�ڽӾ�������
	SpotType spot[MAX_SPOT+1];			//��Ŷ�����Ϣ	
	int n, e;							//������������
}Park_map;								//�ڽӾ���

//���ڽӱ�ʵ�����һ�����ټ���������洢
//Ϊ�˼��������ظ����������ڽӱ���ԭʼ�Ķ�������ƣ�Ҳ����ע��
typedef struct node2
{
	int adjvex;
	int distance;
	char thepath[PATH_LEN];
	struct node2 *nextarc;
} Edge;						//�߽������
typedef struct
{
	SpotType vexdata;
	Edge *firstarc;			//ָ���һ����
} Vex;						//�ڽӱ�ͷ�������
typedef struct
{
	Vex spot[MAX_SPOT + 1];		//�ڽӱ�ͷ�������
	int n, e;
} Graph;

#endif
