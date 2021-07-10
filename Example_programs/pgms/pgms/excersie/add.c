#include<stdio.h>

int add(int x,int y)
{
	return x + y;
}

int main()
{
	int a,b,c;
	a = 10;
	b = 20;
	c = add(a,b);
	printf("%d \n",c);
	
}
