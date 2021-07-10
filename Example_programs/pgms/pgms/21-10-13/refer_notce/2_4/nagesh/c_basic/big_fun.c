#include <stdio.h>

int bigger(int a,int b)
{
	return a > b ? a:b;
}

int main()
{

	int x = 20, y=10;

	printf("biggest nummber is %d",bigger(x,y));

	return 0;
}
