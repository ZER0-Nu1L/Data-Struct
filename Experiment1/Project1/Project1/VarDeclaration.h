#ifndef VAR_DACLARATION_H
#define VAR_DACLARATION_H

//************************************
//学生单链表中数据结点类型定义如下:***
//************************************
typedef struct student {		//定义数据结点类型
	char  sno[12];
	char  sname[10];
	char  sex[4];
	char  major[20];
	struct student *next;	//指向后继数据结点
} StudentList;
typedef struct stable {      //定义学生表
	int  rows;              //学生表记录数
	int  cols;              //学生信息列数
	StudentList *snode;     //学生信息结点
} Stable;

//************************************
//课程单链表中数据结点类型定义如下:***
//************************************
typedef struct course {    //定义数据结点类型
	char  cno[10];
	char  cname[20];
	int  classHours;
	struct course *next;	//指向后继数据结点
} CourseList;
typedef struct ctable {     //定义课程表
	int  rows;             //课程表记录数
	int  cols;             //课程信息列数
	CourseList *cnode;     //课程信息结点
} Ctable;

//************************************
//成绩单链表中数据结点类型定义如下:***
//************************************
typedef struct grade {     //定义数据结点类型
	char  sno[12];
	char  cno[10];
	int  score;
	struct grade *next;	  //指向后继数据结点
} GradeList;
typedef struct gtable {     //定义成绩表
	int  rows;             //成绩表记录数
	int  cols;             //成绩信息列数
	GradeList *gnode;      //成绩信息结点
} Gtable;
//************************************
//所有信息单链表中数据结点类型定义如下:
//************************************
typedef struct all {     //定义数据结点类型
	char  sno[12];
	char  sname[10];
	char  major[20];
	char  cname[10];
	int  score;
	struct all *next;	  //指向后继数据结点
} AllList;
typedef struct atable {     //定义成绩表
	int  rows;             //记录数
	int  cols;             //信息列数
	AllList *anode;      //信息结点
} Atable;

#endif