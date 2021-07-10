#include<stdio.h>
int fun(int n)
{
	static int x, y;
	y = n;
	if(n != 0){
		x = y;
		return (y+1)*(y+1);
	}
	else
		return x*x;
	
}
int main()
{
	int r;
	r = fun(10);
	printf("\n%d", r);
	r = fun(0);
	printf("\n%d", r);
	r = fun(5);
	printf("\n%d", r);
	r = fun(0);
	printf("\n%d\n", r);
	return 0;
}
