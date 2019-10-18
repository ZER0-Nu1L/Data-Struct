#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<limits.h>
#include"VarDeclaration.h"
#include"readline.h"

#define FILE_NAME_OUT "distance.txt"
#define FILE_NAME "AllPath.dat"

void main_interface(void);
void Init_ParkMap(Park_map P[]);
void Input_Save(Park_map P[]);
int Index_spot(char * spot_name, Park_map P[]);
bool check_file(char* filename);

void Floyd(int pathpark[][MAX_SPOT + 1], int n, int dist[][MAX_SPOT + 1], int path[][MAX_SPOT + 1]);
void Allpath_Save(Park_map P[], int dist[][MAX_SPOT + 1], int path[][MAX_SPOT + 1], const char* filename);
void Min_Path(Park_map P[]);
void Min_AllPath(Park_map P[]);

void Set_AdjList(Graph &g, const char * filename);
int Index_vex(char * spot_name, Graph g);
void getname(char*str, char* spotname1, char* spotname2);
void getpath(char*str, char* path);
void Min_Path_Fast(Graph g);

//***********************************************************************************
//**********                         *������*                      ******************
//***********************************************************************************
int main(void)
{
	Park_map P[MAX_SPOT+1];
	Init_ParkMap(P);
	Graph fast_map;
	memset(&fast_map, 0, sizeof(Graph));

	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
	int choice = 0;

	while (1)
	{
		main_interface();
		printf("����������ѡ��");
		scanf(" %d", &choice);
		switch (choice)
		{
			case 0:goto End;break;
			case 1:
				Input_Save(P);
				flag1 = true;
				break;
			case 2:
				if (!flag1)
				{	
					printf("��԰�����ͼ��δ����������ִ�в���1��\n");
					break;
				}
				else
					Min_Path(P);
				break;
			case 3:
				if (!flag1)
					printf("��԰�����ͼ��δ����������ִ�в���1��\n");
				else
				{
					flag3 = true;
					Min_AllPath(P);
				}	
				break;
			case 4:
				if (!flag3)
					printf("���·���ļ�AllPath.dat��δ�ؽ�������ִ�в���3��\n");	
				else 
				{
					Set_AdjList(fast_map, FILE_NAME);
					flag4 = true;
				}
				break;
			case 5:
				if(!flag4)
					printf("���·��������δ����������ִ�в���4��\n");
				else
					Min_Path_Fast(fast_map);
				break;
		}
		printf("\n");
	}

	End: system("pause");
	return 0;
}

//***********************************************************************************
//***                              ������                                         ***
//***********************************************************************************
void main_interface(void)	
{
	printf(
		"*********************************************************\n"
		"************    ��԰���������·����ѯ����   **********\n"
		"*********************************************************\n\n"
		"0���˳�\n"
		"1�����������������ξ���������Լ����ھ��룻������\n"
		"\n---------------------��1����֮����Ч-------------------\n"
		"2����ѯ�������֮����̾��루��ͨ�棩��\n"
		"3���������еľ����֮������·���������浽 AllPath.dat ��\n"
		"\n---------------------��3�������Ч---------------------\n"
		"4������ AllPath.dat �����ݽ������ٲ�ѯ�����������·������\n"
		"\n---------------------��4�������Ч---------------------\n"
		"5����ѯ�������֮����̾��루��Ч�棩��\n\n\n"
		"\n*********************************************************\n"
	);
}
//***********************************************************************************
//��Parkmap���г�ʼ�� 
void Init_ParkMap(Park_map P[])
{
	memset(P, 0, sizeof(Park_map)*(MAX_SPOT+1));
}
//***********************************************************************************
//Ѱ�Ҷ�Ӧ���Ƶľ����ڽ�㼯�ж�Ӧ������
//���û���ҵ�������0��
//�����ڽ���ظ��Եļ��
int Index_spot(char * spot_name, Park_map P[])
{
	int n = P->n;
	if (n == 0)			//�յ����
		return 0;
	for (int i = 1; i <= n; i++)
		if (strcmp(spot_name, P->spot[i].spot_name) == 0)
			return i;
	return 0;//����0��ʾû���ҵ�
}

//***********************************************************************************
//����ļ��Ƿ����
//�漰�ļ��������Ӻ���
bool check_file(const char* filename)
{
	bool flag = true;
	FILE *fp = fopen(filename, "rb");
	//����ļ�������,����һ��������flase;
	if (!fp)
	{
		printf("Ŀ���ļ������ڣ�����Ϊ���½�һ��.\n");
		FILE *fp = fopen(filename, "wb");
		fclose(fp);flag = false;
	}
	printf("\n");
	return flag;
}
//***********************************************************************************
//����ģ��1
//����ֱ�����ڵ��������ξ���������Լ�����֮��ľ��룻
//����ÿ��ֱ�������ľ����ľ���浽�����ļ���
//***********************************************************************************
void Input_Save(Park_map P[])
{
	memset(P, 0, sizeof(Park_map)*(MAX_SPOT + 1));
	int n, dist, num_spot = 0;
	int no1, no2;
	char spotname1[MAX_NAME+1], spotname2[MAX_NAME+1];

	printf("��������һ��Ҫ��������ξ�����Ϣ������");
	scanf(" %d", &n);
	
	while (n <= 0)
	{
		printf("������������������\n");
		scanf(" %d", &n);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("���ǵ�%d�����ݵ����룺\n", i);
		printf("���������ξ���1�����֣�");
		scanf("%s", spotname1);
		printf("���������ξ���2�����֣�");
		scanf("%s", spotname2);
		printf("�������������ξ���֮��ľ��룺");
		scanf("%d", &dist);

		no1 = Index_spot(spotname1, P);
		no2 = Index_spot(spotname2, P);
		if (!no1)
		{
			P->n++;  //P->e++;
			no1 = P->n;
			P->spot[no1].number = no1;
			strcpy(P->spot[no1].spot_name, spotname1);
		}
		if (!no2)
		{
			P->n++;  //P->e++;
			no2 = P->n;
			P->spot[no2].number = no2;
			strcpy(P->spot[no2].spot_name, spotname2);
		}

		if (P->path[no1][no2] != 0)
		{
			printf("·���Ѿ����ڣ�\n");
			continue;
		}
		else
		{
			P->path[no1][no2] = dist;
			P->path[no2][no1] = dist;
			P->e ++;
		}
	}

	if (check_file(FILE_NAME_OUT))
	{
		char chioce;
		printf("��ǰ��Ϣ�ļ��Ѿ����ڣ�������뽫����ԭ�����ݣ��Ƿ����ִ�д˲�������Y/N��");
		do {
			getchar();
			scanf("%c", &chioce);
			chioce = tolower(chioce);//--------------
			switch (chioce)
			{
			case 'y':break;
			case 'n':return;break;
			}
		} while (chioce == 'Y' || chioce == 'N');
	}
	FILE* fp = fopen(FILE_NAME_OUT, "w");
	
	int m = P->e;
	int v = P->n;
	for (int i = 2; i <= v; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (P->path[i][j] != 0)
			{
				fprintf(fp, "%s, %s  %d\n", P->spot[i].spot_name, P->spot[j].spot_name, P->path[i][j]);
				m--;
			}		
		}
		if (m == 0)	break;
	}
	fclose(fp);
	printf("�ļ�����ɹ���\n");
}
//***********************************************************************************
//���·���㷨Floyd
void Floyd(int pathpark[][MAX_SPOT + 1], int n, int dist[][MAX_SPOT + 1], int path[][MAX_SPOT + 1])
{
	for (int i = 1 ;i <= n; i++)
		for (int j = 1;j <= n; j++)
		{
			//dist[i][j] = pathpark[i][j];
			if (pathpark[i][j] == 0)
				//dist[i][j] = MAX_LEN;
				dist[i][j] = MAX_LEN;
			else
				dist[i][j] = pathpark[i][j];	//dist��ʼ��
			if (i != j && pathpark[i][j] != MAX_LEN)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1;j <= n;j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
}
//***********************************************************************************
//�����ж�Ӧ��·���������д���ļ�
void Allpath_Save(Park_map P[], int dist[][MAX_SPOT + 1], int path[][MAX_SPOT + 1], const char* filename)
{
	if (check_file(filename))
	{
		char chioce;
		printf("AllPath.dat�ļ��Ѿ����ڣ�������뽫����ԭ�����ݣ��Ƿ����ִ�д˲�������Y/N��");
		do {
			getchar();
			scanf("%c", &chioce);
			chioce = tolower(chioce);//--------------
			switch (chioce)
			{
			case 'y':break;
			case 'n':return;break;
			}
		} while (chioce == 'Y' || chioce == 'N');
	}
	FILE* fp = fopen(filename, "w");

	int k, s;
	int apath[MAX_SPOT + 1], d;
	for (int i = 1;i <= P->n; i++)
		for (int j = 1;j < i ; j++)
		{
			if (dist[i][j] != MAX_LEN && i != j)
			{
				printf("%s->%s:", P->spot[i].spot_name, P->spot[j].spot_name);
				fprintf(fp, "%s->%s:", P->spot[i].spot_name, P->spot[j].spot_name);
				k = path[i][j];
				d = 0; apath[d] = j;
				while (k != -1 && k != i)
				{
					d++; apath[d] = k;
					k = path[i][k];
				}
				d++; apath[d] = i;
				printf("%s", P->spot[apath[d]].spot_name);
				fprintf(fp, "%s", P->spot[apath[d]].spot_name);
				for (s = d - 1;s >= 0;s--)
				{
					printf(",%s", P->spot[apath[s]].spot_name);
					fprintf(fp, ",%s", P->spot[apath[s]].spot_name);
				}
				fprintf(fp ,"\n·������Ϊ:%d\n", dist[i][j]);
				printf("\n·������Ϊ:%d\n", dist[i][j]);
			}
		}
	fclose(fp);
	printf("�ļ�����ɹ���\n");
}
//***********************************************************************************
//����ģ��2
//ʵ�ּ���������������ξ��������·��
//***********************************************************************************
void  Min_Path(Park_map P[])
{
	int num_spot = 0;
	int no1, no2;
	char spotname1[MAX_NAME + 1], spotname2[MAX_NAME + 1];
	printf("���������ξ���1�����֣�");
	scanf("%s", spotname1);
	printf("���������ξ���2�����֣�");
	scanf("%s", spotname2);
	
	no1 = Index_spot(spotname1, P);
	no2 = Index_spot(spotname2, P);
	while (!no1)
	{
		printf("�����ڸ����ξ��㣡����������.\n");
		printf("���������ξ���1�����֣�");
		scanf("%s", spotname1);
		no1 = Index_spot(spotname1, P);
	}
	while (!no2)
	{
		printf("�����ڸ����ξ��㣡����������.\n");
		printf("���������ξ���2�����֣�");
		scanf("%s", spotname2);
		no2 = Index_spot(spotname2, P);
	}

	int dist[MAX_SPOT + 1][MAX_SPOT + 1] = { {0} };
	int path[MAX_SPOT + 1][MAX_SPOT + 1] = { {0} };
	//memset(dist, 0, sizeof(dist));
	Floyd(P->path, P->n, dist, path);
	if (dist[no1][no2] == MAX_LEN)
		printf("�������ξ���֮�䲻�ɴ\n");
	else
		printf("�������ξ���֮�����̵ľ����ǣ�%d\n", dist[no1][no2]);
}

//***********************************************************************************
//����ģ��3
//�Թ�԰���������ξ��㣬����㷨ʵ�ּ������еľ����֮������·������
//�����·���ϵĸ����ξ��㼰ÿ��·������д������ļ� AllPath.dat ��
//***********************************************************************************
void Min_AllPath(Park_map P[])
{
	int dist[MAX_SPOT + 1][MAX_SPOT + 1] = { {0} };
	int path[MAX_SPOT + 1][MAX_SPOT + 1] = { {0} };
	Floyd(P->path, P->n, dist, path);
	Allpath_Save(P, dist, path, FILE_NAME);
}

//***********************************************************************************
//�����ڶ�λ �������ڽӱ��еĽ�㼯���±�
//����ģ��4���Ӻ���
int Index_vex(char * spot_name, Graph g)
{
	int n = g.n;
	if (n == 0)			//�յ����
		return 0;
	for (int i = 1; i <= n; i++)
		if (strcmp(spot_name, g.spot[i].vexdata.spot_name) == 0)
			return i;
	return 0;//����0��ʾû���ҵ�
}
//***********************************************************************************
//���ļ��������ַ�������ȡ���������������
//����ģ��4���Ӻ���
void getname(char*str, char* spotname1, char* spotname2)
{
	char  ch;
	int i = 0;
	while ((ch = *str++) != '-')
	{
		spotname1[i] = ch;
		i++;
	}
	spotname1[i] = '\0';
	i = 0;
	str++;
	while ((ch = *str++) != ':')
	{
		spotname2[i] = ch;
		i++;
	}
	spotname2[i] = '\0';
	i = 0;
}
//***********************************************************************************
//���ļ��������ַ�����·��
//����ģ��4���Ӻ���
void getpath(char*str, char* path)
{
	char  ch;
	int j = 0;
	while ((ch = *str++) != ':')
		;
	while ((ch = *str++) != '\0')
		path[j++] = ch;
	path[j] = '\0';
}
//***********************************************************************************
//����ģ��4
//���ļ� AllPath.dat �ж����������ξ��������·����Ϣ�����ڴ������й���
//***********************************************************************************
void Set_AdjList(Graph &g, const char * filename)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Ŀ���ļ������ڣ�\n");
		return;
	}
	
	int no1, no2;
	int dist, ch;
	char path[PATH_LEN] = { {0} };
	char spotname1[MAX_NAME + 1], spotname2[MAX_NAME + 1], str[2*MAX_NAME +10];

	Edge* r1, *r2;

	while (fscanf(fp, "%s", str) != EOF)
	{
		while ((ch = fgetc(fp)) != '\n' && ch != EOF)
			;

		getname(str, spotname1, spotname2);
		getpath(str, path);
		no1 = Index_vex(spotname1, g);
		no2 = Index_vex(spotname2, g);
		if (!no1)
		{
			g.n++;  //P->e++;
			no1 = g.n;
			g.spot[no1].vexdata.number = no1;
			strcpy(g.spot[no1].vexdata.spot_name, spotname1);
		}
		if (!no2)
		{
			g.n++;  //P->e++;
			no2 = g.n;
			g.spot[no2].vexdata.number = no2;
			strcpy(g.spot[no2].vexdata.spot_name, spotname2);
		}

		// ��Ϊд���·������������Ķ�д��ȥ�ˣ����п��Ե���

		fscanf(fp, "\n·������Ϊ:%d\n", &dist);
		r1 = (Edge *)malloc(sizeof(Edge));
		r1->distance = dist;
		strcpy(r1->thepath, path);
		r2 = (Edge *)malloc(sizeof(Edge));
		r2->distance = dist;
		strcpy(r2->thepath, path);
		r1->adjvex = no2; 
		r2->adjvex = no1;
		r1->nextarc = g.spot[no1].firstarc;
		r2->nextarc = g.spot[no2].firstarc;
		g.spot[no1].firstarc = r1;
		g.spot[no2].firstarc = r2;
		g.e++;
	}

	fclose(fp);
	printf("�ڴ��������ɹ���\n");
}
//***********************************************************************************
//����ģ��5
//ֱ�Ӵ��ڴ������м������·��
//***********************************************************************************
void Min_Path_Fast(Graph g)
{
	int no1, no2;
	char spotname1[MAX_NAME + 1], spotname2[MAX_NAME + 1];
	printf("���������ξ���1�����֣�");
	scanf("%s", spotname1);
	printf("���������ξ���2�����֣�");
	scanf("%s", spotname2);

	no1 = Index_vex(spotname1, g);
	no2 = Index_vex(spotname2, g);
	while (!no1)
	{
		printf("�����ڸ����ξ��㣡����������.\n");
		printf("���������ξ���1�����֣�");
		scanf("%s", spotname1);
		no1 = Index_vex(spotname1, g);
	}
	while (!no2)
	{
		printf("�����ڸ����ξ��㣡����������.\n");
		printf("���������ξ���2�����֣�");
		scanf("%s", spotname2);
		no2 = Index_vex(spotname2, g);
	}
	Edge * p = g.spot[no1].firstarc;
	while (p != NULL)
	{
		if (p->adjvex == no2)
		{
			printf("%s��%s�����·�������ǣ�%d\n", spotname1, spotname2, p->distance);
			printf("%s��%s�����·����%s\n", spotname1, spotname2, p->thepath);
			return;
		}
		p = p->nextarc;
	}
	printf("�����ڴ�%s��%s��·��\n", spotname1, spotname2);
}