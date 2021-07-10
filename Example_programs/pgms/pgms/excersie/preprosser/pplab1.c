#include<stdio.h>

#define POSBIT(a,pos) (a >> (pos -1)) & 1

int main()
{
	int x = 10, y = 3;
	printf("%d\n",POSBIT(10,4));

	return 0;
}
