#include<stdio.h>

int main()
{
	unsigned short a = 0xffcc;
	unsigned short b = 0xddee,*d;
	unsigned int c;
	unsigned short *ch;
	d = &c;
	*d = b;
	d++;
	*d = a;
	printf("%x\n",c);
	ch = &c;
	printf("%x\n",*ch);
	printf("%x\n",*(ch + 1));
	//printf("%x\n",*(ch + 2));
	//printf("%x\n",*(ch + 3));
		
	return 0;
}
