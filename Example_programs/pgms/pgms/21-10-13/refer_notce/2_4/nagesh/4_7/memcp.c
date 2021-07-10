#include <stdio.h>

void* memcp(void *p, void *q, int size)
{

	unsigned int i = 0;
	char *t = p;

	for(;i < size;i++)
	*(char*)t++ =  *(char *)q++;

	return p;
}

int main()
{

	int a[5] = {1,2,3,4,5};
	int b[5];

	char *s;

	s = (char *) memcp(b,a,20);
	
	printf("%d ",*b);

	return 0;
}
