#include <stdio.h>
#include <queue>	//队列 
using namespace std;
int main(){
	queue<int> q;
	for(int i=1;i<=5;i++){
		q.push(i);	//将i压入队列，即依次入队 1 2 3 4 5 
	}
	printf("%d %d\n",q.front(),q.back());	//访问队头和队尾 
	return 0;
} 
 
