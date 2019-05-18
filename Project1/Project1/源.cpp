#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include"Stack.h"
#include"Queue.h"
#include"readline.h"
#include"VarDeclaration.h"

#define FILE_NAME1 "student.dat"
#define FILE_NAME2 "course.dat"
#define FILE_NAME3 "courseGrade.dat"
#define FILE_NAME4 "studentGrade.dat"

#define STD_NUM 10
#define CRS_NUM 3

void main_interface(void);
void Initialize(Stable *&stb, Ctable *&ctb, Gtable *&gtb, Atable *&atb, Stable *&stb0);

bool check_nullStu(void);
bool check_nullCrs(void);
bool check_nullGrd(void);
bool check_nullAll(void);
void InputStuInfo(void);
void InputCrsInfo(void);
void InputGrdInfo(void);

void GetStuInfo(Stable *stb);
void PrintStuInfo(Stable *stb);
void GetCrsInfo(Ctable *ctb);
void PrintCrsInfo(Ctable *ctb);
void GetGrdInfo(Gtable *gtb);
void PrintGrdInfo(Gtable *gtb);
void GetAllInfo(Stable *stb, Ctable *ctb, Gtable *gtb, Atable *atb);
void PrintAllInfo(Atable *atb);
void SaveAllInfo(Atable *atb);


void GradeSearch(Atable *atb, Ctable * ctb);
void GradeSearchFail(Atable *atb, Ctable * ctb);

void Reverse_StuInfo(Stable *stb, Stable *&stb0 );
void GetAllInfo_Queue(Stable *stb, Ctable *ctb, Gtable *gtb, Atable *atb);
void PrintAllInfo_queue(Atable *atb);

//***********************************************************************************
//**********                         *������*                      ******************
//***********************************************************************************
int main(void)
{
	Stable* stb;
	Ctable* ctb;
	Gtable* gtb;//Ϊ�����ں����и��ģ�����Ϊָ�����
	Atable* atb;
	Stable* stb0;
	//��ͷ��㣻(���ô���)
	Initialize(stb, ctb, gtb, atb, stb0);
	bool flag11 = false, flag12 = false, flag13 = false;
	bool flag1 = false, flag2 = false;
	

	while (1)
	{
		if (flag11 && flag12 && flag13)
			flag1 = true;

		main_interface();
		int choice = 0;
		fflush(stdin);
		printf("����������ѡ��");
		scanf(" %d", &choice);
		switch (choice)
		{
			case 0:goto End;break;
			case 1:InputStuInfo();break;
			case 2:InputCrsInfo();break;
			case 3:InputGrdInfo();break;
			case 4:
					GetStuInfo(stb);
					flag11 = true;
					break;
			case 5:
					GetCrsInfo(ctb);
					flag12 = true;
					break;
			case 6:
					GetGrdInfo(gtb);
					flag13 = true;
					break;
			case 7:
				if (flag1)
				{
					GetAllInfo(stb, ctb, gtb, atb);
					flag2 = true;
				}
				else
					printf("��ǰ�ù��ܲ����ã���4��5��6����֮����Ч��\n");
				break;
			case 8:
				if(flag2)
					GradeSearch(atb, ctb); 
				else
					printf("��ǰ�ù��ܲ����ã���7����֮����Ч��\n");
				break;
			case 9:
				if (flag2)
					GradeSearchFail(atb, ctb); 
				else
					printf("��ǰ�ù��ܲ����ã���7����֮����Ч��\n");
				break;
			case 10:
				if (flag2)
					Reverse_StuInfo(stb, stb0);
				else
					printf("��ǰ�ù��ܲ����ã���7����֮����Ч��\n");
				break;
			case 11:
				if (flag2)
					GetAllInfo_Queue(stb, ctb, gtb, atb);
				else
					printf("��ǰ�ù��ܲ����ã���7����֮����Ч��\n");
				break;
			default:printf("��������Ч��ָ�0-11��!\n");break;
		}
		printf("\n");
	}
End:;
	system("pause");//��������
	return 0;
}
//***********************************************************************************
//***                              ������                                         ***
//***********************************************************************************
void main_interface(void)
{
	printf(
		"***************************************************\n"
		"************     ѧ���γ̳ɼ���ѯ����    **********\n"
		"***************************************************\n"
		"0���˳�\n"
		"1������ѧ����Ϣ�����棻\n"
		"2������γ���Ϣ�����棻\n"
		"3������ɼ���Ϣ�����棻\n"
		"4����ѧ���������У����ѧ����Ϣ��\n"
		"5�����γ̺���������,����γ���Ϣ��\n"
		"6����ѧ�źͿγ̺���������,����ɼ���Ϣ\n"
		"-----��4��5��6����֮����Ч-----\n"
		"7�������Գɼ���������,�������ѧ�����пγ̵Ŀ��Գɼ�,�����棻\n"
		"---------��7�������Ч---------\n"
		"8����ѯָ���γ̺ŵ�����ѧ���Ŀ��Գɼ��������տ��Գɼ����������������Ļ����ʾ��\n"
		"9����ѯָ���γ̺ŵĲ�����ѧ���Ŀ��Գɼ��������տ��Գɼ����������������Ļ����ʾ��\n"
		"10����ѧ�Ž������У����ѧ����Ϣ������ջʵ������\n"
		"11�������Գɼ���������,�������ѧ�����пγ̵Ŀ��Գɼ�,�����棻���ö��У�\n\n"
	);
}
//***********************************************************************************
//��ָ��������г�ʼ������//
//***********************************************************************************
void Initialize(Stable *&stb, Ctable *&ctb, Gtable *&gtb, Atable *&atb, Stable *&stb0)
{
	stb = (Stable *)malloc(sizeof(Stable));
	ctb = (Ctable *)malloc(sizeof(Ctable));
	gtb = (Gtable *)malloc(sizeof(Gtable));
	atb = (Atable *)malloc(sizeof(Atable));
	stb0 = (Stable *)malloc(sizeof(Stable));

	if ((stb->snode = (StudentList*)malloc(sizeof(StudentList))) == NULL)
	{
		printf("Error in mallocing!\n");
		exit(EXIT_FAILURE);
	}
	if ((ctb->cnode = (CourseList*)malloc(sizeof(CourseList))) == NULL)
	{
		printf("Error in mallocing!\n");
		exit(EXIT_FAILURE);
	}
	if ((gtb->gnode = (GradeList*)malloc(sizeof(GradeList))) == NULL)
	{
		printf("Error in mallocing!\n");
		exit(EXIT_FAILURE);
	}
	if ((atb->anode = (AllList*)malloc(sizeof(AllList))) == NULL)
	{
		printf("Error in mallocing!\n");
		exit(EXIT_FAILURE);
	}
	if ((stb0->snode = (StudentList*)malloc(sizeof(StudentList))) == NULL)
	{
		printf("Error in mallocing!\n");
		exit(EXIT_FAILURE);
	}
	stb->snode->next = NULL;stb->cols = 4;stb->rows = 0;
	ctb->cnode->next = NULL;ctb->cols = 3;ctb->rows = 0;
	gtb->gnode->next = NULL;gtb->cols = 3;gtb->rows = 0;
	atb->anode->next = NULL;atb->cols = 5;atb->rows = 0;
	stb0->snode->next = NULL;stb0->cols = 4;stb0->rows = 0;
}
//***********************************************************************************
//����ļ��Ƿ���ڣ�*������������������½�����Ҫ����������
//����10��ѧ����¼�������������רҵ5�ˣ��˹�����רҵ5�ˣ��������ļ�student.dat�У�
//����3�ſγ̣����ݿ⡢���ݽṹ��������ƣ���Ϣ��¼���������ļ�course.dat�У�
//��������10λͬѧ�ֱ�ѡ���������ſγ̵Ŀ��Գɼ����ļ�courseGrade.dat�У�
//***********************************************************************************
bool check_nullStu(void)
{
	bool flag = true;
	FILE *fp1 = fopen(FILE_NAME1, "rb");
	//����ļ�������,����һ��������flase;
	if (!fp1)
	{
		printf("ѧ����Ϣ�ĳ�ʼ���ļ������ڣ�����Ϊ���½�һ��.\n");
		FILE *fp1 = fopen(FILE_NAME1, "wb");
		fclose(fp1);flag = false;
	}
	printf("\n");
	return flag;
}
bool check_nullCrs(void)
{
	bool flag = true;
	FILE *fp2 = fopen(FILE_NAME2, "rb");
	//����ļ�������,����һ��������flase;
	if (!fp2)
	{
		printf("�γ���Ϣ�ĳ�ʼ���ļ������ڣ�����Ϊ���½�һ��.\n");
		FILE *fp2 = fopen(FILE_NAME2, "wb");
		fclose(fp2);flag = false;
	}
	printf("\n");
	return flag;
}
bool check_nullGrd(void)
{
	bool flag = true;
	FILE *fp3 = fopen(FILE_NAME3, "rb");
	//����ļ�������,����һ��������flase;
	if (!fp3)
	{
		printf("�ɼ���Ϣ�ĳ�ʼ���ļ������ڣ�����Ϊ���½�һ��.\n");
		FILE *fp3 = fopen(FILE_NAME3, "wb");
		fclose(fp3);flag = false;
	}
	printf("\n");
	return flag;
}
bool check_nullAll(void)
{
	bool flag = true;
	FILE *fp4 = fopen(FILE_NAME4, "rb");
	//����ļ�������,����һ��������flase;
	if (!fp4)
	{
		printf("����ѧ�����пγ̵Ŀ��Գɼ��ļ������ڣ�����Ϊ���½�һ��.\n");
		FILE *fp4 = fopen(FILE_NAME4, "wb");
		fclose(fp4);flag = false;
	}
	printf("\n");
	return flag;
}
void InputStuInfo()
{
	if (check_nullStu())
	{
		char chioce;
		printf("��ǰѧ����Ϣ�ļ��Ѿ����ڣ�������뽫����ԭ�����ݣ��Ƿ����ִ�д˲�������Y/N��");
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

	FILE *fp1 = fopen(FILE_NAME1, "wb");
	StudentList stl[STD_NUM + 1];//�߼���ţ�����------

//	freopen("C:\\Users\\wcb53\\Desktop\\Project1\\�����ı�����\\student - ����.dat", "r", stdin);
	printf("������10��ѧ����¼�������������רҵ5�ˣ��˹�����רҵ5�ˣ����ݽ������ļ�student.dat\n");
	for (int i = 1; i <= STD_NUM; i++)
	{
		printf("\n��ǰ���������%d��ѧ������Ϣ\n", i);
		printf("��%d��ѧ����ѧ��Ϊ��", i);
		scanf("  %s", stl[i].sno);
		printf("��%d��ѧ��������Ϊ��", i);
		scanf(" %s", stl[i].sname);
		printf("��%d��ѧ�����Ա�Ϊ��(��/Ů)", i);
		scanf(" %s", stl[i].sex);
		printf("��%d��ѧ����רҵΪ��(�������/�˹�����רҵ)", i);
		scanf(" %s", stl[i].major);
		stl[i].next = NULL;
	}
//	fflush(stdout);

	fwrite(stl + 1, sizeof(StudentList), sizeof(stl) / sizeof(StudentList) - 1, fp1);//Ҫ�׵��ʼû�õ��Ǹ�������
	fclose(fp1);
	printf("ѧ����Ϣ����ɹ���\n\n");
}
void InputCrsInfo(void)
{
	if (check_nullCrs())
	{
		char chioce;
		printf("��ǰ�γ���Ϣ�ļ��Ѿ����ڣ�������뽫����ԭ�����ݣ��Ƿ����ִ�д˲�������Y/N��");
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

	FILE *fp2 = fopen(FILE_NAME2, "wb");
	CourseList csl[CRS_NUM + 1];

//	freopen("C:\\Users\\wcb53\\Desktop\\Project1\\�����ı�����\\course - ����.dat", "r", stdin);
	printf("������3�ſγ̣����ݿ⡢���ݽṹ��������ƣ���Ϣ��¼�����ݽ������ļ�course.dat\n");
	for (int i = 1; i <= CRS_NUM; i++)
	{
		printf("\n��ǰ���������%d�ſγ̵���Ϣ\n", i);
		printf("��%d�ŵĿγ̺�Ϊ��", i);
		scanf("  %s", csl[i].cno);
		printf("��%d�ſγ̵�����Ϊ��", i);
		scanf(" %s", csl[i].cname);
		printf("��%d�ſγ̵�ѧʱΪ��", i);
		scanf(" %d", &csl[i].classHours);
		csl[i].next = NULL;
	}
	//	fflush(stdout);
	fwrite(csl + 1, sizeof(CourseList), sizeof(csl) / sizeof(CourseList) - 1, fp2);
	fclose(fp2);
	printf("�γ���Ϣ����ɹ���\n\n");
}
void InputGrdInfo(void)
{
	if (check_nullGrd())
	{
		char chioce;
		getchar();
		printf("��ǰ�ɼ���Ϣ�ļ��Ѿ����ڣ�������뽫����ԭ�����ݣ��Ƿ����ִ�д˲�������Y/N��");
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

	FILE *fp3 = fopen(FILE_NAME3, "wb");
	GradeList gdl[STD_NUM *CRS_NUM + 1];

	//����ѧ���ļ��Ϳγ��ļ�����Ϣ

	if (!check_nullStu())
	{
		printf("��ǰδ��⵽ѧ���ļ���Ϣ����������ѧ����Ϣ������ɼ���Ϣ��\n");
		printf("�ɼ���Ϣ����ʧ�ܣ�\n");
		return;
	}
	if (!check_nullCrs())
	{
		printf("��ǰδ��⵽�γ��ļ���Ϣ����������γ���Ϣ������ɼ���Ϣ��\n");
		printf("�ɼ���Ϣ����ʧ�ܣ�\n");
		return;
	}
	FILE *fp1 = fopen(FILE_NAME1, "rb");
	StudentList stl[STD_NUM + 1];
	fread(stl+1, sizeof(StudentList), sizeof(stl) / sizeof(StudentList)-1, fp1);
	fclose(fp1);

	FILE *fp2 = fopen(FILE_NAME2, "rb");
	CourseList csl[CRS_NUM + 1];
	fread(csl + 1, sizeof(CourseList), sizeof(csl) / sizeof(CourseList) - 1, fp2);
	fclose(fp2);

//	freopen("C:\\Users\\wcb53\\Desktop\\Project1\\�����ı�����\\courseGrade - ����.dat", "r", stdin);
	printf("����������10λͬѧ�ֱ�ѡ���������ſγ̵Ŀ��Գɼ������ݽ������ļ�courseGrade.dat\n");
	for (int i = 1; i <= CRS_NUM; i++)
	{
		printf("\n***��ǰ���������%d�ſγ̿��Գɼ�����Ϣ***\n", i);
		for (int j = 1; j <= STD_NUM; j++)
		{
			printf("\n��%d��ѧ���Ķ�Ӧ���Գɼ�Ϊ��", j);
			scanf("  %d", &gdl[(i - 1)*STD_NUM + j].score);
			strcpy(gdl[(i - 1) * STD_NUM + j].cno, csl[i].cno);
			strcpy(gdl[(i - 1) * STD_NUM + j].sno, stl[j].sno);//˳��д����
			gdl[(i - 1) * STD_NUM + j].next = NULL;
		}
	}
	//	fflush(stdout);
	fwrite(gdl + 1, sizeof(GradeList), sizeof(gdl) / sizeof(GradeList) - 1, fp3);//��ĸд���ˣ�������
	fclose(fp3);
	printf("�ɼ���Ϣ����ɹ���\n\n");
}

//***********************************************************************************
//���ļ�student.dat�ж���ѧ����Ϣ�����ɰ���ѧ���������еĵ�������
//������Ļ����ʾ�����
void GetStuInfo(Stable *stb)
{
	FILE* fp = fopen(FILE_NAME1, "rb");
	StudentList *r = NULL;
	stb->rows = 0;//----------------------------------------------------
	for (int i = 1; i <= STD_NUM; i++)
	{
		StudentList *p = stb->snode->next, *pre = stb->snode;//Ҫ�ŵ����棬ÿһ��ѭ������һ��
		if ((r = (StudentList*)malloc(sizeof(StudentList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		fread(r, sizeof(StudentList), 1, fp);

		if (stb->snode->next == NULL || ( i == 1 && stb->snode->next != NULL))//�ձ����� + �ظ��鿴ʱ��������⣨���º����ٿ���
			stb->snode->next = r;//stb->snode = r;
		else
		{
			while ((p != NULL) && (strcmp(r->sno, p->sno) > 0))//����С��Ū���ˣ���
			{
				pre = p;p = p->next;//��Ȼ����һ�䣬�ѻ�����ȥ�ˣ�������
			}
			if (p == NULL)//��ʱr���ڵ�ѧ��������
			{
				pre->next = r;
				r->next = NULL;
			}
			else if (strcmp(r->sno, p->sno) == 0)
			{
				printf("����ͬ�������ظ���ѧ�����������������룡\n");//
				continue;
			}
			else
			{
				pre->next = r;
				r->next = p;   //break;Ϊʲô��ʱд�������������
			}
		}
		stb->rows++;
	}
	fclose(fp);
	printf("\n�����ǰ�ѧ���������е�ѧ����Ϣ��\n");
	PrintStuInfo(stb);
}
void PrintStuInfo(Stable *stb)
{
	StudentList *p = stb->snode->next;
	if (stb == NULL)
	{
		printf("��ѧ����Ϣ��\n");
		exit(EXIT_FAILURE);
	}
	printf("����ѧ�����¼����%d����ѧ����Ϣ������%d�У�\n", stb->rows, stb->cols);
	printf("ѧ��    ����    �Ա�    רҵ\n");
	for (int i = 1; i <= stb->rows; i++)
	{
		printf("%s\t", p->sno);
		printf("%s\t", p->sname);
		printf("%s\t", p->sex);
		printf("%s\n", p->major);
		p = p->next;
	}
	printf("\n");
}
//***********************************************************************************
//���ļ�course.dat�ж����γ���Ϣ�����ɰ��տγ̺��������еĵ�������
//������Ļ����ʾ�����
void GetCrsInfo(Ctable *ctb)
{
	FILE* fp = fopen(FILE_NAME2, "rb");
	CourseList *r = NULL;
	ctb->rows = 0;
	for (int i = 1; i <= CRS_NUM; i++)
	{
		CourseList *p = ctb->cnode->next, *pre = ctb->cnode;//Ҫ�ŵ����棬ÿһ��ѭ������һ��
		if ((r = (CourseList*)malloc(sizeof(CourseList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		fread(r, sizeof(CourseList), 1, fp);

		if (ctb->cnode->next == NULL || (i == 1 && ctb->cnode->next != NULL))//�ձ�����
			ctb->cnode->next = r;//stb->snode = r;
		else
		{
			while ((p != NULL) && (strcmp(r->cno, p->cno) > 0))
			{
				pre = p;p = p->next;
			}
			if (p == NULL)//��ʱr���ڵĿγ̺�������
			{
				pre->next = r;
				r->next = NULL;
			}
			else
			{
				pre->next = r;
				r->next = p;   //break;Ϊʲô��ʱд�������������
			}
		}
		ctb->rows++;
	}
	fclose(fp);
	PrintCrsInfo(ctb);
}
void PrintCrsInfo(Ctable *ctb)
{
	CourseList *p = ctb->cnode->next;
	if (ctb == NULL)
	{
		printf("�޿γ���Ϣ��\n");
		exit(EXIT_FAILURE);
	}
	printf("\n�����ǰ��γ��������еĿγ���Ϣ��\n");
	printf("���пγ̼�¼����%d�����γ���Ϣ������%d�У�\n", ctb->rows, ctb->cols);
	printf("�γ̺�  �γ�����      ѧʱ\n");
	for (int i = 1; i <= ctb->rows; i++)
	{
		printf("%5s\t", p->cno);
		printf("%-8s\t", p->cname);
		printf("%d\n", p->classHours);
		p = p->next;
	}
	printf("\n");
}
//***********************************************************************************
//���ļ�courseGrade.dat�ж����ɼ���Ϣ�����ɰ���ѧ�źͿγ̺��������еĵ�����������Ļ����ʾ�����
void GetGrdInfo(Gtable *gtb)
{
	FILE* fp = fopen(FILE_NAME3, "rb");
	GradeList *r = NULL;
	gtb->rows = 0;
	for (int i = 1; i <= CRS_NUM*STD_NUM; i++)
	{
		GradeList *p = gtb->gnode->next, *pre = gtb->gnode;//Ҫ�ŵ����棬ÿһ��ѭ������һ��
		if ((r = (GradeList*)malloc(sizeof(GradeList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		fread(r, sizeof(GradeList), 1, fp);

		if (gtb->gnode->next == NULL || (i == 1 && gtb->gnode->next != NULL))//�ձ�����
			gtb->gnode->next = r;//stb->snode = r;
		else//���ؼ��ֺʹιؼ��ֵ�����
		{
			while ((p != NULL) && (strcmp(r->sno, p->sno) > 0))//�Ƚ����ؼ���
			{
				pre = p;p = p->next;
			}
			if (p == NULL)//�ر���----------------------------------------------------------------------
			{
				pre->next = r;
				r->next = NULL;
				gtb->rows++;//-----------------------------------------continue��ʱ�򿴿�������û�ж�ȫ����Ӱ���
				continue;//----------------------------------------------------------------------
			}
			if (strcmp(p->sno, r->sno) == 0)//���ؼ�����ȣ���Ҫ���н�һ���ıȽ�
			{
				while ((p != NULL) && (strcmp(r->cno, p->cno) > 0))
				{
					pre = p;p = p->next;
				}
				if (p == NULL)
				{
					pre->next = r;
					r->next = NULL;
				}
				else
				{
					pre->next = r;
					r->next = p;
				}
			}
			else//���ؼ��ֲ�ͬ
			{
				if (p == NULL)
				{
					pre->next = r;
					r->next = NULL;
				}
				else
				{
					pre->next = r;
					r->next = p;   
				}
			}
		}
		gtb->rows++;
	}
	fclose(fp);
	PrintGrdInfo(gtb);
}
void PrintGrdInfo(Gtable *gtb)
{
	GradeList *p = gtb->gnode->next;
	if (gtb == NULL)
	{
		printf("�޿γ���Ϣ��\n");
		exit(EXIT_FAILURE);
	}
	printf("\n�����ǰ��γ��������еĳɼ���Ϣ��\n");
	printf("���гɼ���¼����%d�����ɼ���Ϣ������%d�У�\n", gtb->rows, gtb->cols);
	printf("�γ̺�    ѧ��  �ɼ�\n");
	for (int i = 1; i <= gtb->rows; i++, p = p->next)
	{
		printf("%5s\t", p->cno);
		printf("%s\t", p->sno);
		printf("%d\n", p->score);
	}
	printf("\n");
}
//***********************************************************************************
//��ѯ����ѧ�����пγ̵Ŀ��Գɼ������ɸÿγ̵ĳɼ�������
//Ҫ�����ѧ�š�ѧ��������רҵ���γ��������Գɼ�����Ϣ��
//���տ��Գɼ��������У�����ѧ���ĸóɼ���Ϣ������ļ�studentGrade.dat�У�ͬʱ����Ļ����ʾ���
void GetAllInfo(Stable *stb, Ctable *ctb, Gtable *gtb, Atable *atb)
{
	AllList *p, *pre, *r;
	GradeList *g; StudentList *s; CourseList *c;//-----------------------------------�����ظ���������
	atb->rows = 0;

	g = gtb->gnode->next;//��ʼ��
	for (int i = 1; i <= ctb->rows * stb->rows; i++)//��¼��
	{
		if ((r = (AllList*)malloc(sizeof(AllList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		
		//����stbѰ��ѧ�Ŷ�Ӧ������,����ctbѰ�ҿγ̺Ŷ�Ӧgtb�Ŀγ�����,��װ�ص�r��//-----####ע���Ⱥ�˳��
		c = ctb->cnode->next;//��ʼ��
		while (c != NULL)
		{
			s = stb->snode->next;//��ʼ��
			while (s != NULL)//������for(i=0;;i++){for(j=0;;j++){if()}}
			{
				if (strcmp(s->sno, g->sno) == 0 && strcmp(c->cno, g->cno) == 0)
				{
					//break;
					goto NEXT;
				}
				s = s->next;
			}
			c = c->next;
		}
		NEXT:;
			strcpy(r->sno, s->sno);strcpy(r->sname, s->sname);strcpy(r->major, s->major);
			strcpy(r->cname, c->cname);
			r->score = g->score;
			r->next = NULL;//û������������أ�����
		
		//���ճɼ���С�������
		p = atb->anode->next, pre = atb->anode;
		if (atb->anode->next == NULL || (i == 1 && atb->anode->next != NULL))
		{
			atb->anode->next = r;
		}
		else
		{
			while (p != NULL && p->score > r->score)//����
			{
				pre = p;p = p->next;
			}
			pre->next = r;
			r->next = p;
		}
		g = g->next;
		atb->rows++;
	}
	PrintAllInfo(atb);
	SaveAllInfo(atb);
}
void PrintAllInfo(Atable *atb)
{
	AllList *p = atb->anode->next;
	if (atb == NULL)
	{
		printf("����Ϣ��\n");
		exit(EXIT_FAILURE);
	}
	printf("\n����������ѧ�����пγ̵Ŀ��Գɼ���\n");
	printf("���гɼ���¼����%d�����ɼ���Ϣ������%d�У�\n", atb->rows, atb->cols);
	printf("ѧ��  \t����  \tרҵ  \t\t�γ���  \t�ɼ�\n");
	for (int i = 0; i < atb->rows; i++, p = p->next)
	{
		printf("%s\t", p->sno);
		printf("%s\t", p->sname);
		printf("%s\t", p->major);
		printf("%-8s\t", p->cname);
		printf("%d\n", p->score);
	}
	printf("\n");
}
void SaveAllInfo(Atable *atb)
{
	if (check_nullAll())
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

	FILE *fp4 = fopen(FILE_NAME4, "wb");
	AllList *p = atb->anode->next;
	while (p != NULL)
	{
		fwrite(p, sizeof(AllList), 1, fp4);//Ҫ�׵��ʼû�õ��Ǹ�������
		p = p->next;
	}
	fclose(fp4);
	printf("��Ϣ����ɹ���\n\n");

}
//***********************************************************************************
//��All�����У���ѯָ���γ̺ŵ�����ѧ���Ŀ��Գɼ������ɸÿγ̵ĳɼ�������
//Ҫ�����ѧ�š�ѧ��������רҵ���γ��������Գɼ�����Ϣ��
//���տ��Գɼ����������������Ļ����ʾ��
void GradeSearch(Atable *atb, Ctable * ctb)
{
	AllList * gs, *r, *p, *pre;//������ͷ�����������,�����������ָ��
	AllList *q, *s = atb->anode->next;//��������atb����¼ÿ���ҵ��Ľ����atb�е���һ��λ��
	if ((gs = (AllList*)malloc(sizeof(AllList))) == NULL)
	{
		printf("Error in mallocing!\n");
		exit(EXIT_FAILURE);
	}
	gs->next = NULL;
	
	char courseno[101], coursename[101];
	printf("\n�����������ѯ�Ŀγ̺�:");
	scanf("%s", courseno);
	//�ҵ��γ̺Ŷ�Ӧ�Ŀγ���
	CourseList *pc = ctb->cnode->next;
	while (pc != NULL)
	{
		if (strcmp(courseno, pc->cno) == 0)
		{
			strcpy(coursename, pc->cname);
			break;
		}
		pc = pc->next;
	}
	if (pc == NULL)
	{
		printf("��δ�ҵ���Ӧ�Ŀγ̣�\n");
		return;
	}
	for (int i = 1; i <= STD_NUM; i++)
	{
		//����ռ�
		if ((r = (AllList*)malloc(sizeof(AllList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		r->next = NULL;
		//��ʼλ��
		q = s;
		//���ݿγ̺���atable���ҵ���Ӧ��������Ϣ,װ��
		while (q != NULL)
		{
			if (strcmp(coursename, q->cname) == 0)
			{
				strcpy(r->major, q->major);
				strcpy(r->sname, q->sname);
				strcpy(r->sno, q->sno);
				strcpy(r->cname, q->cname);
				r->score = q->score;
				break;
			}
			q = q->next;
		}
		//��¼λ��
		s = q->next;
		//���ݳɼ�����
		p = gs->next;pre = gs;
		if (gs->next == NULL)
		{
			gs->next = r;
		}
		else
		{
			while (p != NULL && p->score > r->score)
			{
				pre = p; p = p->next;
			}
			pre->next = r;
			r->next = p;

		}
	}
	//���
	p = gs->next;
	printf("�γ̺�Ϊ%s����Ϣ���£�\n",courseno);
	printf("ѧ��  \t����  \tרҵ  \t\t�γ���  \t�ɼ�\n");
	for (int i = 1; i <= STD_NUM ; i++, p = p->next)
	{
		printf("%s\t", p->sno);
		printf("%s\t", p->sname);
		printf("%s\t", p->major);
		printf("%-8s\t", p->cname);
		printf("%d\n", p->score);
	}
	printf("\n");	
}
//***********************************************************************************
// ��All�������У���ѯָ���γ̺ŵĿ��Գɼ�С��60�ֵ�ѧ���ɼ���Ϣ�����ɸÿγ̵ĳɼ�����
//Ҫ�����ѧ�š�ѧ��������רҵ���γ��������Գɼ�����Ϣ��
//�����տ��Գɼ�������������Ļ����ʾ�����
void GradeSearchFail(Atable *atb, Ctable * ctb)
{
	AllList * gs, *r, *p, *pre;//������ͷ�����������,�����������ָ��
	AllList *q, *s = atb->anode->next;//��������atb����¼ÿ���ҵ��Ľ����atb�е���һ��λ��
	if ((gs = (AllList*)malloc(sizeof(AllList))) == NULL)
	{
		printf("Error in mallocing!\n");
		exit(EXIT_FAILURE);
	}
	gs->next = NULL;

	char courseno[101], coursename[101];
	printf("\n�����������ѯ�Ŀγ̺�:");
	scanf("%s", courseno);
	//�ҵ��γ̺Ŷ�Ӧ�Ŀγ���
	CourseList *pc = ctb->cnode->next;
	while (pc != NULL)
	{
		if (strcmp(courseno, pc->cno) == 0)
		{
			strcpy(coursename, pc->cname);
			break;
		}
		pc = pc->next;
	}
	if (pc == NULL)
	{
		printf("��δ�ҵ���Ӧ�Ŀγ̣�\n");
		return;
	}
	int count = 0;
	while(1)//for (int i = 1; i <= STD_NUM; i++)
	{
		//����ռ�
		if ((r = (AllList*)malloc(sizeof(AllList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		r->next = NULL;
		//��ʼλ��
		q = s;
		//���ݿγ̺���atable���ҵ���Ӧ��������Ϣ,װ��
		while (q != NULL)
		{
			if (strcmp(coursename, q->cname) == 0 && q->score < 60)///////////////////////
			{
				strcpy(r->major, q->major);
				strcpy(r->sname, q->sname);
				strcpy(r->sno, q->sno);
				strcpy(r->cname, q->cname);
				r->score = q->score;
				count++;
				break;
			}
			q = q->next;
		}
		if (q == NULL)
		{
			break;
		}
		//��¼λ��
		s = q->next;
		//���ݳɼ�����
		p = gs->next;pre = gs;
		if (gs->next == NULL)
		{
			gs->next = r;
		}
		else
		{
			while (p != NULL && p->score > r->score)
			{
				pre = p; p = p->next;
			}
			pre->next = r;
			r->next = p;
		}
	}
	//���
	p = gs->next;
	printf("�γ̺�Ϊ%s������ѧ������Ϣ���£�\n", courseno);
	printf("ѧ��  \t����  \tרҵ  \t\t�γ���  \t�ɼ�\n");
	if (count != 0)
	{
		for (int i = 1; i <= count; i++, p = p->next)
		{
			printf("%s\t", p->sno);
			printf("%s\t", p->sname);
			printf("%s\t", p->major);
			printf("%-8s\t", p->cname);
			printf("%d\n", p->score);
		}
		printf("\n");
	}
	else
	{
		printf("�ÿγ�û�в������ѧ������\n");
	}
}
//***********************************************************************************
//ʹ��ջʵ�ֽ�StudentList�������е�ѧ����Ϣ���������µ�����
void Reverse_StuInfo(Stable *stb, Stable *&stb0)
{
	LinkStNode *st;
	InitStack(st);
	ElemType temp;
	StudentList *r, *p, *tail = stb0->snode;//p����������tail����β�壬���ջ
	
	p = stb->snode->next;
	while (p != NULL)
	{
		strcpy(temp.sno, p->sno);
		strcpy(temp.sex, p->sex);
		strcpy(temp.major, p->major);
		strcpy(temp.sname, p->sname);
		Push(st, temp);
		p = p->next;
	}
	while (!StackEmpty(st))
	{
		//��ջ������װ��
		r = (StudentList*)malloc(sizeof(StudentList));
		r->next = NULL;
		Pop(st, temp);
		strcpy(r->sno, temp.sno);
		strcpy(r->sex, temp.sex);
		strcpy(r->major, temp.major);
		strcpy(r->sname, temp.sname);

		tail->next = r;
		tail = r;
		stb0->rows++;
	}
	
	tail->next = NULL;

	DestroyStack(st);
	printf("\n�����ǰ�ѧ�Ž������е�ѧ����Ϣ��4�����򣩣�\n");
	PrintStuInfo(stb0);
}
//***********************************************************************************
//ʹ����ʽ�����������7��Ҫ�󣬽���ʹ�ô�ͷָ���βָ����ʽ���С�
void GetAllInfo_Queue(Stable *stb, Ctable *ctb, Gtable *gtb, Atable *atb)
{
	AllList *p, *pre, *r;
	GradeList *g; StudentList *s; CourseList *c;//�ֱ������Ӧ�ı�
	atb->rows = 0;

	g = gtb->gnode->next;//��ʼ��
	for (int i = 1; i <= ctb->rows * stb->rows; i++)//��¼��
	{
		if ((r = (AllList*)malloc(sizeof(AllList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}

		//����stbѰ��ѧ�Ŷ�Ӧ������,����ctbѰ�ҿγ̺Ŷ�Ӧgtb�Ŀγ�����,��װ�ص�r��//-----####ע���Ⱥ�˳��
		c = ctb->cnode->next;//��ʼ��
		while (c != NULL)
		{
			s = stb->snode->next;//��ʼ��
			while (s != NULL)//������for(i=0;;i++){for(j=0;;j++){if()}}
			{
				if (strcmp(s->sno, g->sno) == 0 && strcmp(c->cno, g->cno) == 0)
				{
					//break;
					goto NEXT;
				}
				s = s->next;
			}
			c = c->next;
		}
	NEXT:;
		strcpy(r->sno, s->sno);strcpy(r->sname, s->sname);strcpy(r->major, s->major);
		strcpy(r->cname, c->cname);
		r->score = g->score;
		r->next = NULL;//û������������أ�����

	//���ճɼ���С�������
		p = atb->anode->next, pre = atb->anode;
		if (atb->anode->next == NULL || (i == 1 && atb->anode->next != NULL))
		{
			atb->anode->next = r;
		}
		else
		{
			while (p != NULL && p->score > r->score)//����
			{
				pre = p;p = p->next;
			}
			pre->next = r;
			r->next = p;
		}
		g = g->next;
		atb->rows++;
	}
	PrintAllInfo_queue(atb);
	SaveAllInfo(atb);
}

void PrintAllInfo_queue(Atable *atb)
{
	LinkQuNode* qu;
	InitQueue(qu);
	DataType temp;

	AllList *q = atb->anode->next;

	printf("\n����������ѧ�����пγ̵Ŀ��Գɼ���\n");
	printf("���гɼ���¼����%d�����ɼ���Ϣ������%d�У�\n", atb->rows, atb->cols);

	while (q != NULL)
	{
		strcpy(temp.cname, q->cname);
		strcpy(temp.major, q->major);
		strcpy(temp.sname, q->sname);
		strcpy(temp.sno, q->sno);
		temp.score = q->score;
		enQueue(qu, temp);
		deQueue(qu, temp);
		printf("%s\t", temp.sno);
		printf("%s\t", temp.sname);
		printf("%s\t", temp.major);
		printf("%-8s\t", temp.cname);
		printf("%d\n", temp.score);
		q = q->next;
	}	
}