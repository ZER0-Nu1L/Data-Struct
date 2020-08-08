#include <stdio.h>
#include <set>
using namespace std;
int main(){
	set<int> st;
	st.insert(2);
	st.insert(5);
	st.insert(4);
	printf("%d\n",st.size());	//输出ste中的元素个数 
	return 0;
}
