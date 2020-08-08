#include <stdio.h>
#include <set>
using namespace std;
int main(){
	set<int> st;
	st.insert(100);
	st.insert(200);
	st.erase(100);	//删除set中值为100的元素
	for(set<int>::iterator it=st.begin();it != st.end();it++){
		printf("%d\n",*it);
	} 
	return 0;
}

