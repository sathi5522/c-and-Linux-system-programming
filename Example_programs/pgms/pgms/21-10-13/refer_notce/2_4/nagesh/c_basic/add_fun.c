#include <stdio.h>

/* Funtion Defination */
int sum(int a, int b)//a,b are formal Arguments
{
	return a + b;
}

int main()
{

	int x, y, ret;

	x = 10;
	y = 20;

	/* Funtion call*/
	ret = sum(x,y);//x,y Actual arguments
	printf("sum : %d\n", ret);

	return 0;
}
