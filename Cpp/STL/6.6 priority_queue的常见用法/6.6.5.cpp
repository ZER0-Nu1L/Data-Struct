#include <stdio.h>
#include <queue>
using namespace std;
int main(){
	priority_queue<int,vector<int>,greater<int> > q;	//最后两个 > 之间有空格 
	q.push(3);
	q.push(4);
	q.push(1);	//greater<int>表示数字小的优先级大 
	printf("%d\n",q.top());	//访问队首元素 
	return 0;
}
