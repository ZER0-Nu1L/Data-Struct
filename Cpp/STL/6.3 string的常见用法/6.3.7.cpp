#include <iostream>
#include <string>
using namespace std;
int main(){
	string str="abcxyz",str2="opq";
	str.insert(str.begin()+3,str2.begin(),str2.end());
	cout<<str<<endl;
	return 0;
}

