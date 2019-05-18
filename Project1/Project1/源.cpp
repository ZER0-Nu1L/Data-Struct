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
//**********                         *主函数*                      ******************
//***********************************************************************************
int main(void)
{
	Stable* stb;
	Ctable* ctb;
	Gtable* gtb;//为了能在函数中更改，故设为指针变量
	Atable* atb;
	Stable* stb0;
	//带头结点；(更好处理)
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
		printf("请输入您的选择：");
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
					printf("当前该功能不可用！在4、5、6步骤之后生效！\n");
				break;
			case 8:
				if(flag2)
					GradeSearch(atb, ctb); 
				else
					printf("当前该功能不可用！在7步骤之后生效！\n");
				break;
			case 9:
				if (flag2)
					GradeSearchFail(atb, ctb); 
				else
					printf("当前该功能不可用！在7步骤之后生效！\n");
				break;
			case 10:
				if (flag2)
					Reverse_StuInfo(stb, stb0);
				else
					printf("当前该功能不可用！在7步骤之后生效！\n");
				break;
			case 11:
				if (flag2)
					GetAllInfo_Queue(stb, ctb, gtb, atb);
				else
					printf("当前该功能不可用！在7步骤之后生效！\n");
				break;
			default:printf("请输入有效的指令（0-11）!\n");break;
		}
		printf("\n");
	}
End:;
	system("pause");//闪退问题
	return 0;
}
//***********************************************************************************
//***                              主界面                                         ***
//***********************************************************************************
void main_interface(void)
{
	printf(
		"***************************************************\n"
		"************     学生课程成绩查询程序    **********\n"
		"***************************************************\n"
		"0、退出\n"
		"1、输入学生信息并保存；\n"
		"2、输入课程信息并保存；\n"
		"3、输入成绩信息并保存；\n"
		"4、按学号升序排列，输出学生信息；\n"
		"5、按课程号升序排列,输出课程信息；\n"
		"6、按学号和课程号升序排列,输出成绩信息\n"
		"-----在4、5、6步骤之后生效-----\n"
		"7、按考试成绩降序排列,输出所有学生所有课程的考试成绩,并保存；\n"
		"---------在7步骤后生效---------\n"
		"8、查询指定课程号的所有学生的考试成绩，并按照考试成绩降序排列输出到屏幕上显示；\n"
		"9、查询指定课程号的不及格学生的考试成绩，并按照考试成绩降序排列输出到屏幕上显示；\n"
		"10、按学号降序排列，输出学生信息；（用栈实现逆序）\n"
		"11、按考试成绩降序排列,输出所有学生所有课程的考试成绩,并保存；（用队列）\n\n"
	);
}
//***********************************************************************************
//对指针变量进行初始化操作//
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
//检查文件是否存在，*后续——如果不存在新建还需要将数据填入
//输入10个学生记录，其中软件技术专业5人，人工智能专业5人，并存入文件student.dat中；
//输入3门课程（数据库、数据结构、程序设计）信息记录，并存入文件course.dat中；
//输入上述10位同学分别选修上述三门课程的考试成绩到文件courseGrade.dat中；
//***********************************************************************************
bool check_nullStu(void)
{
	bool flag = true;
	FILE *fp1 = fopen(FILE_NAME1, "rb");
	//如果文件不存在,创建一个，返回flase;
	if (!fp1)
	{
		printf("学生信息文初始化文件不存在！程序将为您新建一个.\n");
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
	//如果文件不存在,创建一个，返回flase;
	if (!fp2)
	{
		printf("课程信息文初始化文件不存在！程序将为您新建一个.\n");
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
	//如果文件不存在,创建一个，返回flase;
	if (!fp3)
	{
		printf("成绩信息文初始化文件不存在！程序将为您新建一个.\n");
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
	//如果文件不存在,创建一个，返回flase;
	if (!fp4)
	{
		printf("所有学生所有课程的考试成绩文件不存在！程序将为您新建一个.\n");
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
		printf("当前学生信息文件已经存在，如果输入将覆盖原有数据，是否继续执行此操作？（Y/N）");
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
	StudentList stl[STD_NUM + 1];//逻辑序号！！！------

//	freopen("C:\\Users\\wcb53\\Desktop\\Project1\\备份文本数据\\student - 副本.dat", "r", stdin);
	printf("请输入10个学生记录，其中软件技术专业5人，人工智能专业5人，数据将存入文件student.dat\n");
	for (int i = 1; i <= STD_NUM; i++)
	{
		printf("\n当前正在输入第%d个学生的信息\n", i);
		printf("第%d个学生的学号为：", i);
		scanf("  %s", stl[i].sno);
		printf("第%d个学生的姓名为：", i);
		scanf(" %s", stl[i].sname);
		printf("第%d个学生的性别为：(男/女)", i);
		scanf(" %s", stl[i].sex);
		printf("第%d个学生的专业为：(软件技术/人工智能专业)", i);
		scanf(" %s", stl[i].major);
		stl[i].next = NULL;
	}
//	fflush(stdout);

	fwrite(stl + 1, sizeof(StudentList), sizeof(stl) / sizeof(StudentList) - 1, fp1);//要抛掉最开始没用的那个！！！
	fclose(fp1);
	printf("学生信息输入成功！\n\n");
}
void InputCrsInfo(void)
{
	if (check_nullCrs())
	{
		char chioce;
		printf("当前课程信息文件已经存在，如果输入将覆盖原有数据，是否继续执行此操作？（Y/N）");
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

//	freopen("C:\\Users\\wcb53\\Desktop\\Project1\\备份文本数据\\course - 副本.dat", "r", stdin);
	printf("请输入3门课程（数据库、数据结构、程序设计）信息记录，数据将存入文件course.dat\n");
	for (int i = 1; i <= CRS_NUM; i++)
	{
		printf("\n当前正在输入第%d门课程的信息\n", i);
		printf("第%d门的课程号为：", i);
		scanf("  %s", csl[i].cno);
		printf("第%d门课程的名称为：", i);
		scanf(" %s", csl[i].cname);
		printf("第%d门课程的学时为：", i);
		scanf(" %d", &csl[i].classHours);
		csl[i].next = NULL;
	}
	//	fflush(stdout);
	fwrite(csl + 1, sizeof(CourseList), sizeof(csl) / sizeof(CourseList) - 1, fp2);
	fclose(fp2);
	printf("课程信息输入成功！\n\n");
}
void InputGrdInfo(void)
{
	if (check_nullGrd())
	{
		char chioce;
		getchar();
		printf("当前成绩信息文件已经存在，如果输入将覆盖原有数据，是否继续执行此操作？（Y/N）");
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

	//读入学生文件和课程文件的信息

	if (!check_nullStu())
	{
		printf("当前未检测到学生文件信息，请先输入学生信息再输入成绩信息！\n");
		printf("成绩信息输入失败！\n");
		return;
	}
	if (!check_nullCrs())
	{
		printf("当前未检测到课程文件信息，请先输入课程信息再输入成绩信息！\n");
		printf("成绩信息输入失败！\n");
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

//	freopen("C:\\Users\\wcb53\\Desktop\\Project1\\备份文本数据\\courseGrade - 副本.dat", "r", stdin);
	printf("请输入上述10位同学分别选修上述三门课程的考试成绩，数据将存入文件courseGrade.dat\n");
	for (int i = 1; i <= CRS_NUM; i++)
	{
		printf("\n***当前正在输入第%d门课程考试成绩的信息***\n", i);
		for (int j = 1; j <= STD_NUM; j++)
		{
			printf("\n第%d个学生的对应考试成绩为：", j);
			scanf("  %d", &gdl[(i - 1)*STD_NUM + j].score);
			strcpy(gdl[(i - 1) * STD_NUM + j].cno, csl[i].cno);
			strcpy(gdl[(i - 1) * STD_NUM + j].sno, stl[j].sno);//顺序写错了
			gdl[(i - 1) * STD_NUM + j].next = NULL;
		}
	}
	//	fflush(stdout);
	fwrite(gdl + 1, sizeof(GradeList), sizeof(gdl) / sizeof(GradeList) - 1, fp3);//字母写错了！！！！
	fclose(fp3);
	printf("成绩信息输入成功！\n\n");
}

//***********************************************************************************
//从文件student.dat中读出学生信息，生成按照学号升序排列的单向链表
//并在屏幕上显示输出；
void GetStuInfo(Stable *stb)
{
	FILE* fp = fopen(FILE_NAME1, "rb");
	StudentList *r = NULL;
	stb->rows = 0;//----------------------------------------------------
	for (int i = 1; i <= STD_NUM; i++)
	{
		StudentList *p = stb->snode->next, *pre = stb->snode;//要放到里面，每一次循环更新一次
		if ((r = (StudentList*)malloc(sizeof(StudentList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		fread(r, sizeof(StudentList), 1, fp);

		if (stb->snode->next == NULL || ( i == 1 && stb->snode->next != NULL))//空表的情况 + 重复查看时候出现问题（更新后想再看）
			stb->snode->next = r;//stb->snode = r;
		else
		{
			while ((p != NULL) && (strcmp(r->sno, p->sno) > 0))//大于小于弄反了！！
			{
				pre = p;p = p->next;//居然当成一句，把花括号去了！笨蛋。
			}
			if (p == NULL)//此时r对于的学号是最大的
			{
				pre->next = r;
				r->next = NULL;
			}
			else if (strcmp(r->sno, p->sno) == 0)
			{
				printf("出现同名或者重复的学生姓名，请重新输入！\n");//
				continue;
			}
			else
			{
				pre->next = r;
				r->next = p;   //break;为什么当时写了这个？！！！
			}
		}
		stb->rows++;
	}
	fclose(fp);
	printf("\n下面是按学号升序排列的学生信息：\n");
	PrintStuInfo(stb);
}
void PrintStuInfo(Stable *stb)
{
	StudentList *p = stb->snode->next;
	if (stb == NULL)
	{
		printf("无学生信息！\n");
		exit(EXIT_FAILURE);
	}
	printf("其中学生表记录数共%d条，学生信息列数共%d列；\n", stb->rows, stb->cols);
	printf("学号    姓名    性别    专业\n");
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
//从文件course.dat中读出课程信息，生成按照课程号升序排列的单向链表
//并在屏幕上显示输出；
void GetCrsInfo(Ctable *ctb)
{
	FILE* fp = fopen(FILE_NAME2, "rb");
	CourseList *r = NULL;
	ctb->rows = 0;
	for (int i = 1; i <= CRS_NUM; i++)
	{
		CourseList *p = ctb->cnode->next, *pre = ctb->cnode;//要放到里面，每一次循环更新一次
		if ((r = (CourseList*)malloc(sizeof(CourseList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		fread(r, sizeof(CourseList), 1, fp);

		if (ctb->cnode->next == NULL || (i == 1 && ctb->cnode->next != NULL))//空表的情况
			ctb->cnode->next = r;//stb->snode = r;
		else
		{
			while ((p != NULL) && (strcmp(r->cno, p->cno) > 0))
			{
				pre = p;p = p->next;
			}
			if (p == NULL)//此时r对于的课程号是最大的
			{
				pre->next = r;
				r->next = NULL;
			}
			else
			{
				pre->next = r;
				r->next = p;   //break;为什么当时写了这个？！！！
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
		printf("无课程信息！\n");
		exit(EXIT_FAILURE);
	}
	printf("\n下面是按课程升序排列的课程信息：\n");
	printf("其中课程记录数共%d条，课程信息列数共%d列；\n", ctb->rows, ctb->cols);
	printf("课程号  课程名称      学时\n");
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
//从文件courseGrade.dat中读出成绩信息，生成按照学号和课程号升序排列的单链表，并在屏幕上显示输出；
void GetGrdInfo(Gtable *gtb)
{
	FILE* fp = fopen(FILE_NAME3, "rb");
	GradeList *r = NULL;
	gtb->rows = 0;
	for (int i = 1; i <= CRS_NUM*STD_NUM; i++)
	{
		GradeList *p = gtb->gnode->next, *pre = gtb->gnode;//要放到里面，每一次循环更新一次
		if ((r = (GradeList*)malloc(sizeof(GradeList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		fread(r, sizeof(GradeList), 1, fp);

		if (gtb->gnode->next == NULL || (i == 1 && gtb->gnode->next != NULL))//空表的情况
			gtb->gnode->next = r;//stb->snode = r;
		else//主关键字和次关键字的问题
		{
			while ((p != NULL) && (strcmp(r->sno, p->sno) > 0))//比较主关键字
			{
				pre = p;p = p->next;
			}
			if (p == NULL)//特别处理----------------------------------------------------------------------
			{
				pre->next = r;
				r->next = NULL;
				gtb->rows++;//-----------------------------------------continue的时候看看后面有没有对全局有影响的
				continue;//----------------------------------------------------------------------
			}
			if (strcmp(p->sno, r->sno) == 0)//主关键字相等，需要进行进一步的比较
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
			else//主关键字不同
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
		printf("无课程信息！\n");
		exit(EXIT_FAILURE);
	}
	printf("\n下面是按课程升序排列的成绩信息：\n");
	printf("其中成绩记录数共%d条，成绩信息列数共%d列；\n", gtb->rows, gtb->cols);
	printf("课程号    学号  成绩\n");
	for (int i = 1; i <= gtb->rows; i++, p = p->next)
	{
		printf("%5s\t", p->cno);
		printf("%s\t", p->sno);
		printf("%d\n", p->score);
	}
	printf("\n");
}
//***********************************************************************************
//查询所有学生所有课程的考试成绩，生成该课程的成绩单链表，
//要求包括学号、学生姓名、专业、课程名、考试成绩等信息，
//按照考试成绩降序排列，并将学生的该成绩信息输出到文件studentGrade.dat中，同时在屏幕上显示输出
void GetAllInfo(Stable *stb, Ctable *ctb, Gtable *gtb, Atable *atb)
{
	AllList *p, *pre, *r;
	GradeList *g; StudentList *s; CourseList *c;//-----------------------------------避免重复变量定义
	atb->rows = 0;

	g = gtb->gnode->next;//初始化
	for (int i = 1; i <= ctb->rows * stb->rows; i++)//记录数
	{
		if ((r = (AllList*)malloc(sizeof(AllList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		
		//遍历stb寻找学号对应的姓名,遍历ctb寻找课程号对应gtb的课程名称,并装载到r中//-----####注意先后顺序
		c = ctb->cnode->next;//初始化
		while (c != NULL)
		{
			s = stb->snode->next;//初始化
			while (s != NULL)//类似于for(i=0;;i++){for(j=0;;j++){if()}}
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
			r->next = NULL;//没有这句后果很严重！！！
		
		//按照成绩大小有序插入
		p = atb->anode->next, pre = atb->anode;
		if (atb->anode->next == NULL || (i == 1 && atb->anode->next != NULL))
		{
			atb->anode->next = r;
		}
		else
		{
			while (p != NULL && p->score > r->score)//降序
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
		printf("无信息！\n");
		exit(EXIT_FAILURE);
	}
	printf("\n下面是所有学生所有课程的考试成绩：\n");
	printf("其中成绩记录数共%d条，成绩信息列数共%d列；\n", atb->rows, atb->cols);
	printf("学号  \t姓名  \t专业  \t\t课程名  \t成绩\n");
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

	FILE *fp4 = fopen(FILE_NAME4, "wb");
	AllList *p = atb->anode->next;
	while (p != NULL)
	{
		fwrite(p, sizeof(AllList), 1, fp4);//要抛掉最开始没用的那个！！！
		p = p->next;
	}
	fclose(fp4);
	printf("信息输入成功！\n\n");

}
//***********************************************************************************
//在All链表中，查询指定课程号的所有学生的考试成绩，生成该课程的成绩单链表，
//要求包括学号、学生姓名、专业、课程名、考试成绩等信息，
//按照考试成绩降序排列输出到屏幕上显示；
void GradeSearch(Atable *atb, Ctable * ctb)
{
	AllList * gs, *r, *p, *pre;//新链表头结点和新增结点,遍历新链表的指针
	AllList *q, *s = atb->anode->next;//用来遍历atb，记录每次找到的结点在atb中的下一个位置
	if ((gs = (AllList*)malloc(sizeof(AllList))) == NULL)
	{
		printf("Error in mallocing!\n");
		exit(EXIT_FAILURE);
	}
	gs->next = NULL;
	
	char courseno[101], coursename[101];
	printf("\n请输入您想查询的课程号:");
	scanf("%s", courseno);
	//找到课程号对应的课程名
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
		printf("尚未找到对应的课程！\n");
		return;
	}
	for (int i = 1; i <= STD_NUM; i++)
	{
		//申请空间
		if ((r = (AllList*)malloc(sizeof(AllList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		r->next = NULL;
		//初始位置
		q = s;
		//根据课程号在atable中找到对应的其他信息,装载
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
		//记录位置
		s = q->next;
		//根据成绩插入
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
	//输出
	p = gs->next;
	printf("课程号为%s的信息如下：\n",courseno);
	printf("学号  \t姓名  \t专业  \t\t课程名  \t成绩\n");
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
// 在All的链表中，查询指定课程号的考试成绩小于60分的学生成绩信息，生成该课程的成绩链表，
//要求包括学号、学生姓名、专业、课程名、考试成绩等信息，
//并按照考试成绩降序排列在屏幕上显示输出；
void GradeSearchFail(Atable *atb, Ctable * ctb)
{
	AllList * gs, *r, *p, *pre;//新链表头结点和新增结点,遍历新链表的指针
	AllList *q, *s = atb->anode->next;//用来遍历atb，记录每次找到的结点在atb中的下一个位置
	if ((gs = (AllList*)malloc(sizeof(AllList))) == NULL)
	{
		printf("Error in mallocing!\n");
		exit(EXIT_FAILURE);
	}
	gs->next = NULL;

	char courseno[101], coursename[101];
	printf("\n请输入您想查询的课程号:");
	scanf("%s", courseno);
	//找到课程号对应的课程名
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
		printf("尚未找到对应的课程！\n");
		return;
	}
	int count = 0;
	while(1)//for (int i = 1; i <= STD_NUM; i++)
	{
		//申请空间
		if ((r = (AllList*)malloc(sizeof(AllList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}
		r->next = NULL;
		//初始位置
		q = s;
		//根据课程号在atable中找到对应的其他信息,装载
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
		//记录位置
		s = q->next;
		//根据成绩插入
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
	//输出
	p = gs->next;
	printf("课程号为%s不及格学生的信息如下：\n", courseno);
	printf("学号  \t姓名  \t专业  \t\t课程名  \t成绩\n");
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
		printf("该课程没有不及格的学生！！\n");
	}
}
//***********************************************************************************
//使用栈实现将StudentList单链表中的学生信息逆序生存新的链表。
void Reverse_StuInfo(Stable *stb, Stable *&stb0)
{
	LinkStNode *st;
	InitStack(st);
	ElemType temp;
	StudentList *r, *p, *tail = stb0->snode;//p用来遍历，tail用来尾插，配合栈
	
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
		//出栈，数据装载
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
	printf("\n下面是按学号降序排列的学生信息（4的逆序）：\n");
	PrintStuInfo(stb0);
}
//***********************************************************************************
//使用链式队列完成问题7的要求，建议使用带头指针和尾指针链式队列。
void GetAllInfo_Queue(Stable *stb, Ctable *ctb, Gtable *gtb, Atable *atb)
{
	AllList *p, *pre, *r;
	GradeList *g; StudentList *s; CourseList *c;//分别遍历对应的表
	atb->rows = 0;

	g = gtb->gnode->next;//初始化
	for (int i = 1; i <= ctb->rows * stb->rows; i++)//记录数
	{
		if ((r = (AllList*)malloc(sizeof(AllList))) == NULL)
		{
			printf("Error in mallocing!\n");
			exit(EXIT_FAILURE);
		}

		//遍历stb寻找学号对应的姓名,遍历ctb寻找课程号对应gtb的课程名称,并装载到r中//-----####注意先后顺序
		c = ctb->cnode->next;//初始化
		while (c != NULL)
		{
			s = stb->snode->next;//初始化
			while (s != NULL)//类似于for(i=0;;i++){for(j=0;;j++){if()}}
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
		r->next = NULL;//没有这句后果很严重！！！

	//按照成绩大小有序插入
		p = atb->anode->next, pre = atb->anode;
		if (atb->anode->next == NULL || (i == 1 && atb->anode->next != NULL))
		{
			atb->anode->next = r;
		}
		else
		{
			while (p != NULL && p->score > r->score)//降序
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

	printf("\n下面是所有学生所有课程的考试成绩：\n");
	printf("其中成绩记录数共%d条，成绩信息列数共%d列；\n", atb->rows, atb->cols);

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