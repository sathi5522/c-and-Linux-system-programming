#include<stdio.h>

int main()
{

	struct add {
		int a;
		int b;
		int *p;
		int *q;
	};
	struct add a;
	a.p = &a.a;
	a.q = &a.b;
	printf("%u\n",a.p);
	printf("%u\n",a.q);

	return 0;
}
