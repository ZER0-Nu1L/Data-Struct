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
//**********                         *主函数*                      ******************
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
		printf("请输入您的选择：");
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
					printf("公园景点地图尚未建立，请先执行操作1！\n");
					break;
				}
				else
					Min_Path(P);
				break;
			case 3:
				if (!flag1)
					printf("公园景点地图尚未建立，请先执行操作1！\n");
				else
				{
					flag3 = true;
					Min_AllPath(P);
				}	
				break;
			case 4:
				if (!flag3)
					printf("最短路径文件AllPath.dat尚未重建，请先执行操作3！\n");	
				else 
				{
					Set_AdjList(fast_map, FILE_NAME);
					flag4 = true;
				}
				break;
			case 5:
				if(!flag4)
					printf("最短路径链表尚未建立，请先执行操作4！\n");
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
//***                              主界面                                         ***
//***********************************************************************************
void main_interface(void)	
{
	printf(
		"*********************************************************\n"
		"************    公园景点间的最短路径查询程序   **********\n"
		"*********************************************************\n\n"
		"0、退出\n"
		"1、输入相邻两个旅游景点的名字以及相邻距离；并保存\n"
		"\n---------------------在1步骤之后生效-------------------\n"
		"2、查询两个结点之间最短距离（普通版）；\n"
		"3、计算所有的景点对之间的最短路径，并保存到 AllPath.dat 中\n"
		"\n---------------------在3步骤后生效---------------------\n"
		"4、利用 AllPath.dat 的数据建立快速查询两景点间的最短路径链表\n"
		"\n---------------------在4步骤后生效---------------------\n"
		"5、查询两个结点之间最短距离（高效版）；\n\n\n"
		"\n*********************************************************\n"
	);
}
//***********************************************************************************
//对Parkmap进行初始化 
void Init_ParkMap(Park_map P[])
{
	memset(P, 0, sizeof(Park_map)*(MAX_SPOT+1));
}
//***********************************************************************************
//寻找对应名称的景点在结点集中对应的索引
//如果没有找到，返回0；
//可用于结点重复性的检查
int Index_spot(char * spot_name, Park_map P[])
{
	int n = P->n;
	if (n == 0)			//空的情况
		return 0;
	for (int i = 1; i <= n; i++)
		if (strcmp(spot_name, P->spot[i].spot_name) == 0)
			return i;
	return 0;//返回0表示没有找到
}

//***********************************************************************************
//检查文件是否存在
//涉及文件操作的子函数
bool check_file(const char* filename)
{
	bool flag = true;
	FILE *fp = fopen(filename, "rb");
	//如果文件不存在,创建一个，返回flase;
	if (!fp)
	{
		printf("目标文件不存在！程序将为您新建一个.\n");
		FILE *fp = fopen(filename, "wb");
		fclose(fp);flag = false;
	}
	printf("\n");
	return flag;
}
//***********************************************************************************
//功能模块1
//输入直接相邻的两个旅游景点的名字以及它们之间的距离；
//并将每对直接相连的景点间的距离存到磁盘文件中
//***********************************************************************************
void Input_Save(Park_map P[])
{
	memset(P, 0, sizeof(Park_map)*(MAX_SPOT + 1));
	int n, dist, num_spot = 0;
	int no1, no2;
	char spotname1[MAX_NAME+1], spotname2[MAX_NAME+1];

	printf("请输入您一共要输入的旅游景点信息组数：");
	scanf(" %d", &n);
	
	while (n <= 0)
	{
		printf("请输入大于零的整数！\n");
		scanf(" %d", &n);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("这是第%d组数据的输入：\n", i);
		printf("请输入旅游景点1的名字：");
		scanf("%s", spotname1);
		printf("请输入旅游景点2的名字：");
		scanf("%s", spotname2);
		printf("请输入两个旅游景点之间的距离：");
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
			printf("路径已经存在！\n");
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
		printf("当前信息文件已经存在，如果输入将覆盖原有数据，是否继续执行此操作？（Y/N）");
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
	printf("文件保存成功！\n");
}
//***********************************************************************************
//最短路径算法Floyd
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
				dist[i][j] = pathpark[i][j];	//dist初始化
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
//将所有对应的路径都输出并写进文件
void Allpath_Save(Park_map P[], int dist[][MAX_SPOT + 1], int path[][MAX_SPOT + 1], const char* filename)
{
	if (check_file(filename))
	{
		char chioce;
		printf("AllPath.dat文件已经存在，如果输入将覆盖原有数据，是否继续执行此操作？（Y/N）");
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
				fprintf(fp ,"\n路径长度为:%d\n", dist[i][j]);
				printf("\n路径长度为:%d\n", dist[i][j]);
			}
		}
	fclose(fp);
	printf("文件保存成功！\n");
}
//***********************************************************************************
//功能模块2
//实现计算给定的两个旅游景点间的最短路径
//***********************************************************************************
void  Min_Path(Park_map P[])
{
	int num_spot = 0;
	int no1, no2;
	char spotname1[MAX_NAME + 1], spotname2[MAX_NAME + 1];
	printf("请输入旅游景点1的名字：");
	scanf("%s", spotname1);
	printf("请输入旅游景点2的名字：");
	scanf("%s", spotname2);
	
	no1 = Index_spot(spotname1, P);
	no2 = Index_spot(spotname2, P);
	while (!no1)
	{
		printf("不存在该旅游景点！请重新输入.\n");
		printf("请输入旅游景点1的名字：");
		scanf("%s", spotname1);
		no1 = Index_spot(spotname1, P);
	}
	while (!no2)
	{
		printf("不存在该旅游景点！请重新输入.\n");
		printf("请输入旅游景点2的名字：");
		scanf("%s", spotname2);
		no2 = Index_spot(spotname2, P);
	}

	int dist[MAX_SPOT + 1][MAX_SPOT + 1] = { {0} };
	int path[MAX_SPOT + 1][MAX_SPOT + 1] = { {0} };
	//memset(dist, 0, sizeof(dist));
	Floyd(P->path, P->n, dist, path);
	if (dist[no1][no2] == MAX_LEN)
		printf("两个旅游景点之间不可达！\n");
	else
		printf("两个旅游景点之间的最短的距离是：%d\n", dist[no1][no2]);
}

//***********************************************************************************
//功能模块3
//对公园的所有旅游景点，设计算法实现计算所有的景点对之间的最短路径，并
//将最短路径上的各旅游景点及每段路径长度写入磁盘文件 AllPath.dat 中
//***********************************************************************************
void Min_AllPath(Park_map P[])
{
	int dist[MAX_SPOT + 1][MAX_SPOT + 1] = { {0} };
	int path[MAX_SPOT + 1][MAX_SPOT + 1] = { {0} };
	Floyd(P->path, P->n, dist, path);
	Allpath_Save(P, dist, path, FILE_NAME);
}

//***********************************************************************************
//用于在定位 景点在邻接表中的结点集的下标
//功能模块4的子函数
int Index_vex(char * spot_name, Graph g)
{
	int n = g.n;
	if (n == 0)			//空的情况
		return 0;
	for (int i = 1; i <= n; i++)
		if (strcmp(spot_name, g.spot[i].vexdata.spot_name) == 0)
			return i;
	return 0;//返回0表示没有找到
}
//***********************************************************************************
//从文件读出的字符串中提取出两个景点的名字
//功能模块4的子函数
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
//从文件读出的字符串中路径
//功能模块4的子函数
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
//功能模块4
//从文件 AllPath.dat 中读出所有旅游景点间的最短路径信息，到内存链表中管理；
//***********************************************************************************
void Set_AdjList(Graph &g, const char * filename)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("目标文件不存在！\n");
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

		// 因为写入的路径把两个方向的都写进去了，所有可以当做

		fscanf(fp, "\n路径长度为:%d\n", &dist);
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
	printf("内存链表建立成功！\n");
}
//***********************************************************************************
//功能模块5
//直接从内存链表中检索最短路径
//***********************************************************************************
void Min_Path_Fast(Graph g)
{
	int no1, no2;
	char spotname1[MAX_NAME + 1], spotname2[MAX_NAME + 1];
	printf("请输入旅游景点1的名字：");
	scanf("%s", spotname1);
	printf("请输入旅游景点2的名字：");
	scanf("%s", spotname2);

	no1 = Index_vex(spotname1, g);
	no2 = Index_vex(spotname2, g);
	while (!no1)
	{
		printf("不存在该旅游景点！请重新输入.\n");
		printf("请输入旅游景点1的名字：");
		scanf("%s", spotname1);
		no1 = Index_vex(spotname1, g);
	}
	while (!no2)
	{
		printf("不存在该旅游景点！请重新输入.\n");
		printf("请输入旅游景点2的名字：");
		scanf("%s", spotname2);
		no2 = Index_vex(spotname2, g);
	}
	Edge * p = g.spot[no1].firstarc;
	while (p != NULL)
	{
		if (p->adjvex == no2)
		{
			printf("%s到%s的最短路径长度是：%d\n", spotname1, spotname2, p->distance);
			printf("%s到%s的最短路径：%s\n", spotname1, spotname2, p->thepath);
			return;
		}
		p = p->nextarc;
	}
	printf("不存在从%s到%s的路径\n", spotname1, spotname2);
}