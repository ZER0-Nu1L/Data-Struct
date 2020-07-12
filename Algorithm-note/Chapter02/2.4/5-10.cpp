#include <cstdio>

int main(void)
{
	double a = 2, b = 1, t = 0;
	double sum = 0;
	for(int i = 0; i < 20; i++) {
		sum += a/b;
		t = b;
		b = a;		//Ë³ÐòÎÊÌâ
		a = a + t;
	}
	printf("%.6f\n", sum);
	return 0;
}
