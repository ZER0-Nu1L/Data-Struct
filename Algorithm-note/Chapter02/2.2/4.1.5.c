#include <cstdio>

int main(void) {
	double n, a, b, c, d, e;
	scanf("%lf", &n);
	if(n <= 100000 ) {
		printf("%.2lf\n", n*0.1);
	} else if(n>100000 && n<=200000) {
		a = (n-100000)*0.075+100000*0.1;
		printf("%.2lf\n",a);
	}else if(n>200000&&n<=400000) {
		b = (n-200000)*0.05+100000*0.075+100000*0.1;
		printf("%.2lf\n",b);
	}else if(n>400000&&n<=600000) {
		c = (n-400000)*0.03+200000*0.05+100000*0.075+100000*0.1;
		printf("%.2lf\n",c);
	}else if(n>600000&&n<=1000000) {
		d = (n-600000)*0.015+200000*0.03+200000*0.05+100000*0.075+100000*0.1;
		printf("%.2lf\n",d);
	}else{
		e = (n-1000000)*0.01+400000*0.015+200000*0.03+200000*0.05+100000*0.075+100000*0.1;
		printf("%.2lf\n",e);
	}
	return 0;
}
