#include <cstdio>
#include <cmath>

int main(void)
{
	double a, b, c;
	double r1, r2;
	scanf("%lf %lf %lf", &a, &b, &c);
	r1 = (-b + sqrt(b*b - 4*a*c)) / 2;
	r2 = (-b - sqrt(b*b - 4*a*c)) / 2;
	printf("r1=%7.2f\n", r1);
	printf("r2=%7.2f\n", r2);
	return 0;
}
