#include<stdio.h>

#define CAPITALCHAR(x) ((x >= 65) &(x <= 90))?1:0

int main()
{
	char ch = 'H';
	printf("%d\n",CAPITALCHAR(ch));

	return 0;
}
