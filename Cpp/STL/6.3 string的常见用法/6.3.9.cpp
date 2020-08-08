#include <string> 
#include <iostream>
using namespace std;
int main(){
	string str="abcdefg";
	str.erase(str.begin()+2,str.end()-1);
	cout<<str<<endl;
	return 0;
} 

