/*
	ADT Graph{
	数据对象V：
			 V是具有相同特性的数据元素的集合，称为顶点集
	数据关系：
			 R={VR}
			 VR={<v, w>|v, w∈V且P(V, W),<v, w>表示从v到w的弧，谓词
			  P(V,W)定义了弧<v, w>的意义或信息}
	基本操作：
			 GraphCreate(G, V, VR)         //以顶点集合V和弧集合VR构造图G
			 GraphDestroy(G)                    //删除图G，如果G存在，删除G
			 GraphLocateVertex(G, V)     //定位顶点操作，返回V在G中的位置
			 GraphGetVertex(G, V)           //取值操作，返回V的值
			 GraphFirstAdj(G, V)                    //查询G中V的第一个邻接顶点
             GraphNextAdj(G, V, W)              //求V相对于W的下一个邻接点
             GraphInsertVertex(G, V)             //插入顶点
             GraphDeleteVertex(G, V)            //删除顶点
             GraphInsertArc(G, V, W)           //插入弧
             GraphDeleteArc(G, V)                //删除弧
             DFSTtraverse(G, V, Visit())        //深度遍历图G，Visit()是顶点的应用函数 
             BFSTtraverse(G, V, Visit())        //广度遍历图G
   
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