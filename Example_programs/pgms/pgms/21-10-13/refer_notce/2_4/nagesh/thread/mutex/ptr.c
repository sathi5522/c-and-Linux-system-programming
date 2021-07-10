#include <stdio.h>

void fuc(int (*p)[5][2])
{

	printf("%d\n",*p);

}

int main()
{

	int a[5][2]={1,0,0,0,0,0,0,0,0,0};
	int (*b)[5][2];
	int (*c)[10];
//	c = &a;
	b = &a;
	fuc(&a);
	
	return 0;

}
