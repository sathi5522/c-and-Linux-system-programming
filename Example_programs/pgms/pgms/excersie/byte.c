#include<stdio.h>

int main()
{
	unsigned int a = 0xffddccee;
	unsigned char *p;
	p = &a;
	printf("%x\n",*p);
	printf("%x\n",*(p + 1));
	printf("%x\n",*(p + 2));
	printf("%x\n",*(p + 3));
	
	return 0;

}
