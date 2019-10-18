#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;
void getname(char*str, char* spotname1, char* spotname2)
{
	char  ch;
	int i = 0;
	while ((ch = *str++) != '-')
	{
		spotname1[i] = ch;
		i++;
	}
	spotname1[i] = '\0';
	i = 0;
	str++;
	while ((ch = *str++) != ':')
	{
		spotname2[i] = ch;
		i++;
	}
	spotname2[i] = '\0';
	i = 0;
	while ((ch = *str++) != '\n')
		;
}

int main(void)
{
	char spotname1[100], spotname2[100],str[100] = "b->a:b ,a\n路径长度为:3";
	getInfo(str, spotname1, spotname2);
	printf("%s \n%s", spotname1, spotname2);
	return 0;
}
