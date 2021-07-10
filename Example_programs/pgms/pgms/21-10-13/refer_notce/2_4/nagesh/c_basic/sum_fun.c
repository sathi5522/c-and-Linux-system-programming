#include <stdio.h>

void sum(int a ,int b)
{
	int c;
	
	c = a + b;

	printf("sum of digits : %d",c);

}

int main()
{
 	int x, y;
	
	printf("enter any two numbers");
	scanf("%d%d",&x,&y);

	sum(x,y);

	return 0;
	

}
