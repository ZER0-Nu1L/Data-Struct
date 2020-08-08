#include <stdio.h>
#include <queue>
using namespace std;
int main(){
	priority_queue<int> q;
	q.push(3);
	q.push(4);
	q.push(1);
	printf("%d\n",q.top());	//访问队首元素 
	q.pop();	//令队首元素出队 
	printf("%d\n",q.top()); 
	return 0;
}

 
