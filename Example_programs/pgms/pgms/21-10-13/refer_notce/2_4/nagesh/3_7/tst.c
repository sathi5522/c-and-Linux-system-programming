#include<stdio.h>

int main()
{

	const int a = 10;
	int *p = (int *)&a;

	*p = 100;

	printf("%d\n",a);

	return 0;
}
