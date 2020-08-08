#include <stdio.h>
#include <algorithm>	//只是想获取预查询的元素的下标，方法如下 
using namespace std;
int main(){
	int a[10]={1,2,2,3,3,3,5,5,5,5};	//注意数组下标从0开始
	//寻找 3
	printf("%d, %d\n",lower_bound(a,a+10,3)-a,upper_bound(a,a+10,3)-a); 
	return 0;
}


