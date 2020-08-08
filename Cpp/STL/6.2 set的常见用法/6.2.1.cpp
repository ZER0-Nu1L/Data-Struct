#include <stdio.h>
#include <set>
using namespace std;
int main(){	//set中的元素自动递增排序，且自动去重复元素 
	set<int> st;
	st.insert(3);	//将insert(x)插入set中
	st.insert(5);
	st.insert(2);
	st.insert(3);
	for(set<int>::iterator it = st.begin();it != st.end();it++){
		printf("%d",*it);
	} 
	return 0;
}

 
