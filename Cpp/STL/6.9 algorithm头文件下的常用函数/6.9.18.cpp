#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string str1,string str2){
	return str1.length() < str2.length();	//按string的长度从小到大排序 
} 
int main(){
	string str[3]={"bbbb","cc","aaa"};
	sort(str,str+3,cmp);	//排序 
	for(int i=0;i<3;i++){
		cout << str[i] << endl;
	} 
	return 0;
}
