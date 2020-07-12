#include <cstdio> 

int main(void)
{
	double a, b, t;
	scanf("%lf %lf", &a, &b);
	if(a > b) {
		t = a; a = b; b = t;
	}
	printf("%.2f %.2f\n", a, b);
	return 0;
}
