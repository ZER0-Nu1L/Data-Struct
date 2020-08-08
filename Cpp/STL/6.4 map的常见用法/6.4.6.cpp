#include <stdio.h>
#include <map>
using namespace std;
int main(){
	map<char,int> mp;
	mp['a'] = 1;
	mp['b'] = 2;
	mp['c'] = 3;
	map<char,int>::iterator it = mp.find('b');	//令it指向键为b的映射 
	mp.erase(it,mp.end());	//删除b 2 
	for(map<char,int>::iterator it = mp.begin();it != mp.end();it++){
		printf("%c %d\n",it->first,it->second);
	}
	return 0;
}
