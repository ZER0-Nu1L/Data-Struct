#include <stdio.h>
#include <stack>
using namespace std;
int main(){
	stack<int> st;
	if(st.empty() == true){	//一开始栈内没有元素，为空 
		printf("Empty\n");
	}else{
		printf("Not Empty\n");
	}
	st.push(1);
	if(st.empty() == true){	//在加入 “1”后，栈非空 
		printf("Empty\n");
	}else{
		printf("Not Empty\n");
	}
	return 0;
}
