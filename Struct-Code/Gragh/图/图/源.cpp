/*
	ADT Graph{
	���ݶ���V��
			 V�Ǿ�����ͬ���Ե�����Ԫ�صļ��ϣ���Ϊ���㼯
	���ݹ�ϵ��
			 R={VR}
			 VR={<v, w>|v, w��V��P(V, W),<v, w>��ʾ��v��w�Ļ���ν��
			  P(V,W)�����˻�<v, w>���������Ϣ}
	����������
			 GraphCreate(G, V, VR)         //�Զ��㼯��V�ͻ�����VR����ͼG
			 GraphDestroy(G)                    //ɾ��ͼG�����G���ڣ�ɾ��G
			 GraphLocateVertex(G, V)     //��λ�������������V��G�е�λ��
			 GraphGetVertex(G, V)           //ȡֵ����������V��ֵ
			 GraphFirstAdj(G, V)                    //��ѯG��V�ĵ�һ���ڽӶ���
             GraphNextAdj(G, V, W)              //��V�����W����һ���ڽӵ�
             GraphInsertVertex(G, V)             //���붥��
             GraphDeleteVertex(G, V)            //ɾ������
             GraphInsertArc(G, V, W)           //���뻡
             GraphDeleteArc(G, V)                //ɾ����
             DFSTtraverse(G, V, Visit())        //��ȱ���ͼG��Visit()�Ƕ����Ӧ�ú��� 
             BFSTtraverse(G, V, Visit())        //��ȱ���ͼG
   
              }ADT Graph
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"SequenceDiagram.h"
	

int main(void)
{
	
	system("pause");
	return 0;
}