#include <stdio.h>
#include <string>
using namespace std;
int main(){	//通过下标去访问 
	string str= "abcd";
	for(int i=0;i<str.length();i++){
		printf("%c",str[i]); 
	} 
	return 0;
}



