#include <cstdio>

int  main(void)
{
	double a, b, c, t;
	scanf("%lf %lf %lf", &a, &b, &c);
	if(a > b) {
		t = a; a = b; b = t;
	}
	if(a > c) {
		t = a; a = c; c = t;
	}
	if(b > c) {
		t = b; b = c; c = t;
	}
	printf("%.2f %.2f %.2f", a, b, c);
	return 0;
}
