#ifndef VAR_DACLARATION_H
#define VAR_DACLARATION_H

typedef char datatype;
typedef struct node {
	datatype data;
	struct node* lchild, *rchild;
}BT;

#endif