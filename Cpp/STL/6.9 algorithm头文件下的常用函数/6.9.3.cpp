#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int a[10]={10,11,12,13,14,15};
	reverse(a,a+4);	//½«a[0]~a[3]·´×ª
	for(int i=0;i<6;i++){
		printf("%d ",a[i]);
	} 
	return 0;
}

 
