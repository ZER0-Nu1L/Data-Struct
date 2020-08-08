#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int a[]={'T','D','A','K'};
	sort(a,a+4);	//将a[0]~a[3]从小到大排序 
	for(int i=0;i<4;i++){
		printf("%c",a[i]);
	} 
	return 0;
}

