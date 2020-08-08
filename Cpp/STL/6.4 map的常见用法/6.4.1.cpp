#include <stdio.h>
#include <map>
using namespace std;
int main(){
	map<char,int> mp;
	mp['c'] = 20;
	mp['c'] = 30;	//20±»¸²¸Ç
	printf("%d\n",mp['c']);	//Êä³ö 
 	return 0;
}

 
