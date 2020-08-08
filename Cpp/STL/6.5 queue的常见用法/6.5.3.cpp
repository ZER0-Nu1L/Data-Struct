#include <stdio.h>
#include <queue>	//队列 
using namespace std;
int main(){
	queue<int> q;
	if(q.empty() == true){	//一开始队列无元素 
		printf("Empty\n");
	} else{
		printf("Not Empty\n");
	} 
	q.push(1);
	if(q.empty() == true){	//在入队 ”1“后，队列非空 
		printf("Empty\n");
	} else{
		printf("Not Empty\n");
	} 
	return 0;
} 
 
