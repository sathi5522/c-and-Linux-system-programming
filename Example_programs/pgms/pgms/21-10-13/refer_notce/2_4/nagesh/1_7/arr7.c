#include <stdio.h>

unsigned short int * copy(unsigned short *p,unsigned short *q,unsigned long n)
{

	unsigned long i;

	for(i = 0; i < n; i++)
		p[i] = q[i];

	return p;
	
}

int main()
{

	unsigned long size = 5,i;
	unsigned short  s[size], d[size],*f ;

	printf("enter source  array value :\n");

	for(i = 0; i < size; i++)
		scanf("%hd",&s[i]);

	f = copy(d,s,size);

	printf("destination array values :\n");

	for(i = 0; i < size; i++)
	printf("%hd\n",f[i]);

	return 0;
}
