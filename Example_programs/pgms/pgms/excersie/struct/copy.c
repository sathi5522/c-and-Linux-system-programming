#include<stdio.h>

int main()
{
	struct x {
		int a;
		int b;
	};
	struct x x1;
	x1.a = 10;
	x1.b = 20;
	struct x x2;
	x2.a = x1.a;
	x2.b = x1.b;
	printf("%d %d %d %d \n",x1.a,x1.b,x2.a,x2.b);
}
