#include <stdio.h>

void add(int x, int y, int *r)
{

	*r = x+ y;
}


int main()
{

	int a, b, c ;
	a = 10;
	b = 20;
	add(a, b, &c);
	printf("%d\n",c);
	return 0;
}
