#include<stdio.h>

int main()
{
	unsigned int a = 0xffccddee;
	char *p,temp1,temp2;
	p = &a;

	temp1 = *(p + 1);
	*(p + 1) = *(p + 2);
	*(p + 2) = temp1;
	temp2 = *(p + 3);
	*(p + 3) = *(p);
	*(p) = temp2;
	printf("%x\n",a);
	
	return 0;
}
