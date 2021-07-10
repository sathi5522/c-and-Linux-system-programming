#include<stdio.h>
int fun(int x, int y)
{
	int z;
	z = x+y;
	return z;
}
int main()
{
	int a = 10, b = 15, c;
	c = fun(a,b);
	printf("%d", c);
}
