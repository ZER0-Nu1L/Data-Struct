#include <cstdio>

int main(void)
{
	int a, b, c, max;
	scanf("%d %d %d", &a, &b, &c);
	if(a > b) {
		max = a; a = b; b = max;
	}
	max = b>c ? b : c;
	printf("%d\n", max);
	
	return 0;
}
