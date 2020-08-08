#include <stdio.h>
#include <queue>	//队列 
using namespace std;
int main(){
	queue<int> q;
	for(int i=1;i<=5;i++){
		q.push(i);	//将i压入队列，即依次入队 1 2 3 4 5 
	}
	for(int i=1;i<=3;i++){
		q.pop();	//出队首元素三次，即依次出队 1 2 3 
	}
	printf("%d\n",q.front());	//访问队头 
	return 0;
} 
 
