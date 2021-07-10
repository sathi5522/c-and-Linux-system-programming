#include <stdio.h>

void bin(unsigned long int,short int);
int main()
{

	unsigned int a = 0xfffefffe;

	unsigned char *p;

	p = (char *)&a;

	
	bin(*p,sizeof *p);
	printf("\n");

	*p = *(p + 1);
	bin(*p,sizeof *p);
	printf("\n");

	*p = *(p + 2);
	bin(*p,sizeof *p);
	printf("\n");

	*p = *(p + 3);
	bin(*p,sizeof *p);
	printf("\n");

	return 0;
	

}

