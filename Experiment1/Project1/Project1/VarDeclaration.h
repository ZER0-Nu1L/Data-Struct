#ifndef VAR_DACLARATION_H
#define VAR_DACLARATION_H

//************************************
//ѧ�������������ݽ�����Ͷ�������:***
//************************************
typedef struct student {		//�������ݽ������
	char  sno[12];
	char  sname[10];
	char  sex[4];
	char  major[20];
	struct student *next;	//ָ�������ݽ��
} StudentList;
typedef struct stable {      //����ѧ����
	int  rows;              //ѧ�����¼��
	int  cols;              //ѧ����Ϣ����
	StudentList *snode;     //ѧ����Ϣ���
} Stable;

//************************************
//�γ̵����������ݽ�����Ͷ�������:***
//************************************
typedef struct course {    //�������ݽ������
	char  cno[10];
	char  cname[20];
	int  classHours;
	struct course *next;	//ָ�������ݽ��
} CourseList;
typedef struct ctable {     //����γ̱�
	int  rows;             //�γ̱��¼��
	int  cols;             //�γ���Ϣ����
	CourseList *cnode;     //�γ���Ϣ���
} Ctable;

//************************************
//�ɼ������������ݽ�����Ͷ�������:***
//************************************
typedef struct grade {     //�������ݽ������
	char  sno[12];
	char  cno[10];
	int  score;
	struct grade *next;	  //ָ�������ݽ��
} GradeList;
typedef struct gtable {     //����ɼ���
	int  rows;             //�ɼ����¼��
	int  cols;             //�ɼ���Ϣ����
	GradeList *gnode;      //�ɼ���Ϣ���
} Gtable;
//************************************
//������Ϣ�����������ݽ�����Ͷ�������:
//************************************
typedef struct all {     //�������ݽ������
	char  sno[12];
	char  sname[10];
	char  major[20];
	char  cname[10];
	int  score;
	struct all *next;	  //ָ�������ݽ��
} AllList;
typedef struct atable {     //����ɼ���
	int  rows;             //��¼��
	int  cols;             //��Ϣ����
	AllList *anode;      //��Ϣ���
} Atable;

#endif