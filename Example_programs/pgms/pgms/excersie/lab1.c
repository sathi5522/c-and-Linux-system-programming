#include<stdio.h>

	struct a {
		int a;
		int b;
		int c;
	};
int fun(struct a x)
{
	return x.a + x.b;
}

int main()
{

	struct a x = {10,50};


	x.c =  fun(x);
	printf("%d \n",x.c);

	return 0;
}
