#include <stdio.h>
#include <queue>
using namespace std;
int main(){
	priority_queue<int> q;
	q.push(3);
	q.push(4);
	q.push(1);
	printf("%d\n",q.size());	//返回队列元素个数 
	return 0;
}
