#include<stdio.h>

#define TOGGLE(a,pos) {\
			int x = 1;\
			x = x << (pos-1);\
			a = a ^ x;\
			printf("%d\n",a);\
			}

int main()
{
	unsigned int y = 10, z = 3;
	TOGGLE(y,z)

	return 0;
}
