

**Description**

```
从键盘输入3个实数a, b, c，通过比较交换，将最小值存储在变量a中，最大值存储在变量c中，中间值存储在变量b中，
并按照从小到大的顺序输出这三个数a, b, c。
```

**Coding**

```Cpp
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
```

**Reflection**



**Description**

```
/*
有如下分数序列:
2/1, 3/2, 5/3, 8/5, 13/8, 21/13, ...
求出次数列的前20项之和。
*/
```

**Coding**

```cpp
#include <cstdio>

int main(void)
{
	double a = 2, b = 1, t = 0;
	double sum = 0;
	for(int i = 0; i < 20; i++) {
		sum += a/b;
		t = b;
		b = a;		//顺序问题
		a = a + t;
	}
	printf("%.6f\n", sum);
	return 0;
}
```

**Reflection**



