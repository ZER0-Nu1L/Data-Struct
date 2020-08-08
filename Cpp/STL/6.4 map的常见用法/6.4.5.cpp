#include <stdio.h>
#include <map>
using namespace std;
int main(){
	map<char,int> mp;
	mp['a'] = 1;
	mp['b'] = 2;
	mp['c'] = 3;
	mp.erase('b');	//É¾³ýb 2 
	for(map<char,int>::iterator it = mp.begin();it != mp.end();it++){
		printf("%c %d\n",it->first,it->second);
	}
	return 0;
}
 
