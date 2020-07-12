#include <cstdio>
#include <cmath>

int main(void)
{
	double a, b, c;
	double delta;
	double r1, r2;
	
	scanf("%lf %lf %lf", &a, &b, &c);
	delta = b*b - 4 * a * c;
	if(delta < 0)
	{
		printf("No real roots!\n");
	}
	else
	{
		r1 = (-b + sqrt(delta))/2;
		r2 = (-b - sqrt(delta))/2;
		printf("r1=%f\n", r1);
		printf("r2=%f\n", r2);
	}
	return 0;
}
