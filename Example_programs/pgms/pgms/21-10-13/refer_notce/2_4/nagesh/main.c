#include <stdio.h>

int fact(int);
int sum(int);
int main()
{
	int i;

	printf("enter any number\n");
	scanf("%d",&i);

	printf("fact : %d\n sum : %d\n",fact(i),sum(i));

	return 0;
}
