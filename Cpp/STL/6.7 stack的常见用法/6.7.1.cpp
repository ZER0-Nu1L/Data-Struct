#include <stdio.h>
#include <stack>
using namespace std;
int main(){
	stack<int> st;
	for(int i=1;i<=5;i++){
		st.push(i);	//把i压入栈，依次1 2 3 4 5 
	}
	printf("%d\n",st.top());	//top()取栈顶元素 
	return 0;
}


