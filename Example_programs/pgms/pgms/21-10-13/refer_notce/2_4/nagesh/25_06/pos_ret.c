#include <stdio.h>

void bin(unsigned long int,short int);

void pos_ret(unsigned int a,unsigned  int b,unsigned  short int pos,unsigned  short int nob)
{
	unsigned int c = 0xffffffff,g,l;
	
		
	g = b & (c << (pos -1));
	bin(g,sizeof g);
	printf("\n");
	l = pos -1;
	pos = (pos-1) + nob;
	c = c >> (31 - pos);
	a = g & c;
	a = a >> l;
	bin(a,sizeof a);

	
}
