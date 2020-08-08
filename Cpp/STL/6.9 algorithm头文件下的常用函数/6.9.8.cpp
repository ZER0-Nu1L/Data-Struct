#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	double a[]={9.0,1.4,-2.1,-1};
	sort(a,a+4);	//将a[0]~a[3]从小到大排序 
	for(int i=0;i<4;i++){
		printf("%.1lf ",a[i]);
	} 
	return 0;
}

